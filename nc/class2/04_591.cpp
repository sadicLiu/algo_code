#include <iostream>
#include <map>
#include <vector>

using namespace std;

class ConnectingGraph3
{
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    ConnectingGraph3(int n)
    {
        // initialize your data structure here.
        for (int i = 1; i <= n; ++i)
        {
            parents[i] = i;
            sizes[i] = 1;
            count = n;
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

    void connect(int a, int b)
    {
        // write your code here
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

        count--;
    }

    /**
     * @return: An integer
     */
    int query()
    {
        // write your code here
        return count;
    }

private:
    map<int, int> parents;
    map<int, int> sizes;
    int count;
};