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
    /**
     * @param matrix: a matrix of integers
     * @param k: An integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0 || k < 1)
            throw "invalid input";

        int rows = matrix.size();
        int cols = matrix[0].size();

        if (rows * cols < k)
            throw "size of matrix invalid";

        int dx[] = {0, 1};
        int dy[] = {1, 0};

        bool *visit = new bool[rows * cols]();

        priority_queue<Node, vector<Node>, MinHeapComparator> minHeap;
        minHeap.push(Node(matrix[0][0], 0, 0));

        for (int i = 0; i < k - 1; ++i)
        {
            Node cur = minHeap.top();
            minHeap.pop();

            for (int j = 0; j < 2; ++j)
            {
                int nextX = cur.x + dx[j];
                int nextY = cur.y + dy[j];
                if (nextX < rows && nextY < cols && !visit[nextX * cols + nextY])
                {
                    minHeap.push(Node(matrix[nextX][nextY], nextX, nextY));
                    visit[nextX * cols + nextY] = true;
                }
            }
        }

        delete[] visit;
        return minHeap.top().value;
    }
};