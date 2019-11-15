#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

class Node
{
    int value;
};

class UnionFindSet
{
private:
    map<Node, Node> parentMap;
    map<Node, int> sizeMap;

public:
    UnionFindSet(vector<Node> nodes)
    {
        for (int i = 0; i < nodes.size(); ++i)
        {
            parentMap[nodes[i]] = nodes[i];
            sizeMap[nodes[i]] = i;
        }
    }

    Node findHead(Node node)
    {
        stack<Node> container;
        Node cur = node;
        Node parent = parentMap[cur];

        while (&cur != &parent)
        {
            container.push(cur);
            cur = parent;
            parent = parentMap[cur];
        }
        while (!container.empty())
        {
            cur = container.top();
            container.pop();
            parentMap[cur] = parent;
        }

        return parent;
    }

    bool isSameSet(Node a, Node b)
    {
        Node headA = findHead(a);
        Node headB = findHead(b);
        return &headA == &headB;
    }

    void merge(Node a, Node b)
    {
        Node headA = findHead(a);
        Node headB = findHead(b);
        if (&headA == &headB)
            return;

        int sizeA = sizeMap[headA];
        int sizeB = sizeMap[headB];
        if (sizeA > sizeB)
        {
            parentMap[headB] = headA;
            sizeMap[headA] = sizeA + sizeB;
        } else
        {
            parentMap[headA] = headB;
            sizeMap[headB] = sizeA + sizeB;
        }
    }
};

int main()
{


    return 0;
}