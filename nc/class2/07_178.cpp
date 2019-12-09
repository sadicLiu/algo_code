#include <iostream>
#include <vector>
#include <map>

using namespace std;

class UnionFindSet
{
private:
    map<int, int> parents;
    map<int, int> sizes;

public:
    UnionFindSet(int n)
    {
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

    bool merge(int a, int b)
    {
        int headA = findHead(a);
        int headB = findHead(b);
        if (headA == headB)
            return false;

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

        return true;
    }
};

class Solution
{
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges)
    {
        if (n == 0)
            return false;
        for (int j = 0; j < edges.size(); ++j)
        {
            for (int i = 0; i < 2; ++i)
            {
                if (edges[j][i] >= n)
                    return false;
            }
        }

        UnionFindSet findSet(n);
        for (int i = 0; i < edges.size(); ++i)
        {
            bool result = findSet.merge(edges[i][0], edges[i][1]);
            if (!result)
                return false;
        }

        int root = findSet.findHead(0);
        for (int k = 1; k < n; ++k)
        {
            if (root != findSet.findHead(k))
                return false;
        }

        return true;
    }
};