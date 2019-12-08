#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Point
{
    int x;
    int y;

    Point() : x(0), y(0)
    {}

    Point(int a, int b) : x(a), y(b)
    {}
};

class UnionFindSet
{
private:
    map<int, int> parents;
    map<int, int> sizes;

public:
    int mergeTimes;

    UnionFindSet(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            parents[i] = i;
            sizes[i] = 1;
        }
        mergeTimes = 0;
    }

    int findHead(int node)
    {
        int cur = node;
        int parent = parents[cur];
        vector<int> nodes;
        while (cur != parent)
        {
            nodes.push_back(cur);
            cur = parent;
            parent = parents[cur];
        }
        for (int i = 0; i < nodes.size(); ++i)
        {
            cur = nodes[i];
            parents[cur] = parent;
        }

        return parent;
    }

    void merge(int a, int b)
    {
        int headA = findHead(a);
        int headB = findHead(b);
        if (headA == headB)
            return;

        int sizeA = sizes[headA];
        int sizeB = sizes[headB];
        if (sizeA > sizeB)
        {
            parents[headB] = headA;
            sizes[headA] += sizes[headB];
        } else
        {
            parents[headA] = headB;
            sizes[headB] += sizes[headA];
        }
        mergeTimes++;
    }
};

class Solution
{
public:
    vector<int> numIslands2(int n, int m, vector<Point> &operators)
    {
        vector<int> result;
        if (n < 1 || m < 1 || operators.size() == 0)
            return result;

        int grid[n][m];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
                grid[i][j] = 0;
        }
        UnionFindSet findSet(n * m);

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        for (int k = 0; k < operators.size(); ++k)
        {
            int x = operators[k].x;
            int y = operators[k].y;
            if (grid[x][y])
            {
                result.push_back(result[result.size() - 1]);
                continue;
            }

            grid[x][y] = 1;
            for (int i = 0; i < 4; ++i)
            {
                int nextX = x + dx[i];
                int nextY = y + dy[i];

                if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && grid[nextX][nextY])
                    findSet.merge(x * m + y, nextX * m + nextY);
            }

            result.push_back(k + 1 - findSet.mergeTimes);
        }

        return result;
    }
};