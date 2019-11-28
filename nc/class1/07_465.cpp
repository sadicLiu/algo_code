#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int value;
    int x, y;

    Node(int value, int x, int y) : value(value), x(x), y(y)
    {}
};

struct MinHeapComparator
{
    bool operator()(Node a, Node b)
    {
        return a.value > b.value;  //小顶堆
    }
};

class Solution
{
public:
    int kthSmallest(vector<int> &a, vector<int> &b, int k)
    {
        if (a.size() == 0 || b.size() == 0 || a.size() != b.size() || a.size() * b.size() < k)
            throw "invalid input";

        priority_queue<Node, vector<Node>, MinHeapComparator> minHeap;
        minHeap.push(Node(a[0] + b[0], 0, 0));

        int dx[] = {0, 1};
        int dy[] = {1, 0};
        bool *visit = new bool[a.size() * b.size()]();

        for (int i = 0; i < k; ++i)
        {
            Node cur = minHeap.top();
            minHeap.pop();
            if (i == k - 1)
                return cur.value;

            for (int j = 0; j < 2; ++j)
            {
                int nextX = cur.x + dx[j];
                int nextY = cur.y + dy[j];
                if (nextX < a.size() && nextY < b.size() && !visit[nextX * b.size() + nextY])
                {
                    minHeap.push(Node(a[nextX] + b[nextY], nextX, nextY));
                    visit[nextX * a.size() + nextY] = true;
                }
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> a = {1, 7, 11};
    vector<int> b = {2, 4, 6};
    cout << s.kthSmallest(a, b, 3) << endl;
    cout << s.kthSmallest(a, b, 4) << endl;
    cout << s.kthSmallest(a, b, 8) << endl;

    return 0;
}