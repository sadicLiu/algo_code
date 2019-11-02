#include <iostream>

using namespace std;

// 转圈打印矩阵

void printOneCircle(const int *arr, int aR, int aC, int bR, int bC, const int rows, const int cols)
{
    if (aR == bR)
    {
        for (int i = aC; i <= bC; ++i)
            cout << arr[aR * cols + i] << " ";
    } else if (aC == bC)
    {
        for (int i = aR; i <= bR; ++i)
            cout << arr[i * cols + aC] << " ";
    } else
    {
        for (int i = aC; i < bC; i++)
            cout << arr[aR * cols + i] << " ";
        for (int i = aR; i < bR; i++)
            cout << arr[i * cols + bC] << " ";
        for (int i = bC; i > aC; i--)
            cout << arr[bR * cols + i] << " ";
        for (int i = bR; i > aR; i--)
            cout << arr[i * cols + aC] << " ";
    }
}

void printMatrixInCircle(const int *arr, const int rows, const int cols)
{
    if (arr == nullptr || rows < 1 || cols < 1)
        return;

    int aR = 0, aC = 0;
    int bR = rows - 1, bC = cols - 1;
    while (aR <= bR && aC <= bC)
    {
        printOneCircle(arr, aR++, aC++, bR--, bC--, rows, cols);
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int arr2[] = {1, 2, 3};
    int arr3[] = {1, 2, 3};

    printMatrixInCircle(arr, 3, 4);
    printMatrixInCircle(arr2, 1, 3);
    printMatrixInCircle(arr3, 3, 1);

    return 0;
}