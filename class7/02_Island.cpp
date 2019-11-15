#include <iostream>

using namespace std;

// 矩阵中1连成的区域称为一个岛, 判断一个矩阵中有几个岛
// 这道题如果是大规模矩阵, 可以应用并查集, 将矩阵分解, 并行计算

int infect(int *arr, int r, int c, int rows, int cols)
{
    if (r < 0 || r >= rows || c < 0 || c >= cols || arr[r * cols + c] != 1)
        return 0;

    arr[r * cols + c] = 2;
    infect(arr, r + 1, c, rows, cols);
    infect(arr, r - 1, c, rows, cols);
    infect(arr, r, c + 1, rows, cols);
    infect(arr, r, c - 1, rows, cols);

    return 1;
}

int getIsland(int *arr, int rows, int cols)
{
    if (arr == nullptr || rows < 1 || cols < 1)
        return 0;

    int result = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result += infect(arr, i, j, rows, cols);
        }
    }

    return result;
}

int main()
{
    int arr[] = {1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0};
    int rows = 3, cols = 6;

    cout << "Island number: " << getIsland(arr, rows, cols) << endl;

    return 0;
}