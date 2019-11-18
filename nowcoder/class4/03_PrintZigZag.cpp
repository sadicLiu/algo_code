#include <iostream>

using namespace std;

// 之字形打印矩阵
// 三目运算符在这里不太好, 容易出错

void printLine(int *arr, int aR, int aC, int bR, int bC, bool fromUp, int rows, int cols)
{
    if (fromUp)
    {
        for (int i = aR; i <= bR; ++i)
        {
            cout << arr[i * cols + aC] << " ";
            aC--;
        }
    } else
    {
        for (int i = bR; i >= aR; --i)
        {
            cout << arr[i * cols + bC] << " ";
            bC++;
        }
    }
}

void printZigZag(int *arr, int rows, int cols)
{
    if (arr == nullptr)
        return;

    int aR = 0, bR = 0, aC = 0, bC = 0;
    bool fromUp = false;
    while (aR < rows)
    {
        printLine(arr, aR, aC, bR, bC, fromUp, rows, cols);
        if (aC < cols - 1)
            aC++;
        else
            aR++;

        if (bR < rows - 1)
            bR++;
        else
            bC++;

        fromUp = !fromUp;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int rows = 3, cols = 4;
    printZigZag(arr, rows, cols);

    return 0;
}