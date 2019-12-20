#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Cell
{
    int x, y;
    int height;

    Cell(int x, int y, int height) : x(x), y(y), height(height)
    {
    }
};

struct MinHeapHeightComparator
{
    bool operator()(Cell a, Cell b)
    {
        return a.height > b.height;
    }
};

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heights)
    {
        if (heights.size() < 3 || heights[0].size() < 3)
            return 0;

        int rows = heights.size(), cols = heights[0].size();
        bool *visit = new bool[rows * cols]();
        priority_queue<Cell, vector<Cell>, MinHeapHeightComparator> cells;
        initState(heights, cells, visit);

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        int res = 0;
        while (!cells.empty())
        {
            Cell minCell = cells.top();
            cells.pop();

            for (int i = 0; i < 4; ++i)
            {
                int nextX = minCell.x + dx[i];
                int nextY = minCell.y + dy[i];
                if (nextX >= 0 && nextX < rows && nextY >= 0 && nextY < cols && !visit[nextX * cols + nextY])
                {
                    // minCell是外圈所有海拔中最低的地方, 只要这个地方不漏水, 其他地方一定不可能漏水
                    visit[nextX * cols + nextY] = true;
                    cells.push(Cell(nextX, nextY, max(heights[nextX][nextY], minCell.height)));
                    res += max(0, minCell.height - heights[nextX][nextY]);
                }
            }
        }

        delete[] visit;
        return res;
    }

    // 把最外圈的元素压入小根堆
    void initState(vector<vector<int>> &heights, priority_queue<Cell, vector<Cell>, MinHeapHeightComparator> &cells,
                   bool *visit)
    {
        int rows = heights.size();
        int cols = heights[0].size();
        Cell *cell;
        for (int i = 0; i < cols; ++i)
        {
            // 第一行
            cell = new Cell(0, i, heights[0][i]);
            cells.push(*cell);
            visit[i] = true;

            // 最后一行
            cell = new Cell(rows - 1, i, heights[rows - 1][i]);
            cells.push(*cell);
            visit[(rows - 1) * cols + i] = true;
        }
        for (int j = 1; j < rows - 1; ++j)
        {
            // 第一列
            cell = new Cell(j, 0, heights[j][0]);
            cells.push(*cell);
            visit[j * cols] = true;

            // 最后一列
            cell = new Cell(j, cols - 1, heights[j][cols - 1]);
            cells.push(*cell);
            visit[j * cols + cols - 1] = true;
        }
    }
};


