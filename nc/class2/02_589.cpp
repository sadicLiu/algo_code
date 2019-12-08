#include <iostream>
#include <map>
#include <vector>

using namespace std;

class UnionFindSet
{
private:
    map<int, int> parents;
    map<int, int> sizes;

public:
    UnionFindSet(vector<int> &nodes)
    {
        for (int i = 0; i < nodes.size(); ++i)
        {
            int cur = nodes[i];
            parents[cur] = cur;
            sizes[cur] = 1;
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
    }

    bool isSameSet(int a, int b)
    {
        return findHead(a) == findHead(b);
    }

    void connect(int a, int b)
    {
        merge(a, b);
    }

    bool query(int a, int b)
    {
        return isSameSet(a, b);
    }
};

int main()
{
    vector<int> nodes{1, 2, 3, 4, 5};
    UnionFindSet findSet(nodes);

    cout << findSet.query(1, 2) << endl;

    findSet.connect(1, 2);
    cout << findSet.query(1, 3) << endl;

    findSet.connect(2, 4);
    cout << findSet.query(1, 4) << endl;

    return 0;
}
