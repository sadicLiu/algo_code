#include <iostream>
#include <vector>

using namespace std;

/*notes:
 * 并查集，一种用来解决集合查询合并的数据结构
 * 查找、合并的时间复杂度为 O(1)
 * */

class UnionFindSet
{
private:
    int *parents;
    int *sizes;

public:
    UnionFindSet(int *nodes, int num)
    {
        parents = new int[num + 1];
        sizes = new int[num + 1];
        for (int i = 1; i <= num; ++i)
        {
            parents[i] = i;
            sizes[i] = 1;
        }
    }

    ~UnionFindSet()
    {
        delete[] parents;
        delete[] sizes;
    }

    int findHead(int node)
    {
        vector<int> nodes;
        int cur = node;
        int parent = parents[cur];
        while (parent != cur)
        {
            nodes.push_back(cur);
            cur = parent;
            parent = parents[cur];
        }

        for (int i = 0; i < nodes.size(); ++i)
        {
            int tmp = nodes[i];
            parents[tmp] = parent;
        }
    }

    void merge(int a, int b)
    {
        int headA = findHead(a);
        int headB = findHead(b);

        if (headA == headB)
            return;

        int sizeA = sizes[a];
        int sizeB = sizes[b];
        if (sizeA > sizeB)
        {
            parents[b] = a;
            sizes[a] += sizes[b];
        } else
        {
            parents[a] = b;
            sizes[b] += sizes[a];
        }
    }

    bool isSameSet(int a, int b)
    {
        return parents[a] == parents[b];
    }

    bool query(int a, int b)
    {
        return isSameSet(a, b);
    }

    void connect(int a, int b)
    {
        if (isSameSet(a, b))
            return;

        merge(a, b);
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    UnionFindSet findSet(arr, sizeof(arr) / sizeof(int));
    cout << findSet.query(1, 2) << endl;

    findSet.connect(1, 2);
    cout << findSet.query(1, 2) << endl;

    findSet.connect(2, 4);
    cout << findSet.query(1, 4) << endl;

    return 0;
}