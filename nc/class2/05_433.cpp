#include <iostream>
#include <vector>
#include <map>

using namespace std;

class UnionFindSet
{
private:
    map<int, int> parents;
    map<int, int> sizes;
    int mergeTimes;

public:
    UnionFindSet(int n)
    {
        mergeTimes = 0;
        for (int i = 0; i < n; ++i)
        {
            parents[i] = i;
            sizes[i] = 1;
        }
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

    int getMergeTimes()
    {
        return mergeTimes;
    }
};

class Solution
{
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid)
    {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;

        int rows = grid.size();
        int cols = grid[0].size();

        UnionFindSet findSet(rows * cols);
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};

        int numOnes = 0;
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (grid[r][c])
                {
                    numOnes++;
                    for (int i = 0; i < 4; ++i)
                    {
                        int nextRow = r + dx[i];
                        int nextCol = c + dy[i];
                        if (nextRow >= 0 && nextRow < rows
                            && nextCol >= 0 && nextCol < cols
                            && grid[nextRow][nextCol])
                        {
                            findSet.merge(r * cols + c, nextRow * cols + nextCol);
                        }
                    }
                }
            }
        }


        return numOnes - findSet.getMergeTimes();
    }
};