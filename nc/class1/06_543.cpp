#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*notes: 见到数组先排序*/

struct Node
{
    int x, y;
    int value;

    Node(int x, int y, int value) : x(x), y(y), value(value)
    {}
};

struct MaxHeapComparator
{
    bool operator()(Node a, Node b)
    {
        return a.value < b.value;
    }
};

class Solution
{
public:
    int kthInArrays(vector<vector<int>> &arr, int k)
    {
        if (arr.size() == 0 || arr[0].size() == 0 || k < 1)
            throw "invalid input";

        int rows = arr.size();
        int cols = arr[0].size();

        if (rows * cols < k)
            throw "arr size too small";

        for (int i = 0; i < arr.size(); ++i)
        {
            sort(arr[i].begin(), arr[i].end(), greater<int>());
        }

        priority_queue<Node, vector<Node>, MaxHeapComparator> maxHeap;
        int dx[] = {0, 1};
        int dy[] = {1, 0};
        bool *visit = new bool[rows * cols]();
        maxHeap.push(Node(0, 0, arr[0][0]));

        for (int j = 0; j < k - 1; ++j)
        {
            Node cur = maxHeap.top();
            maxHeap.pop();
            for (int i = 0; i < 2; ++i)
            {
                int nextX = cur.x + dx[i];
                int nextY = cur.y + dy[i];
                if (nextX < rows && nextY < cols && !visit[nextX * cols + nextY])
                {
                    maxHeap.push(Node(nextX, nextY, arr[nextX][nextY]));
                    visit[nextX * cols + nextY] = true;
                }
            }
        }

        return maxHeap.top().value;
    }
};

int main()
{
    vector<vector<int>> arr = {{9, 3, 2, 4, 7},
                               {1, 2, 3, 4, 8}};

    Solution s;
    cout << s.kthInArrays(arr, 1) << endl;
    cout << s.kthInArrays(arr, 2) << endl;
    cout << s.kthInArrays(arr, 3) << endl;

    return 0;
}