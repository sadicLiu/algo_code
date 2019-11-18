#include <iostream>
#include <cmath>

using namespace std;

// 将正方形矩阵旋转90度

void rotateInCircle(int *arr, int size, int aR, int aC, int bR, int bC)
{
    if (aR == bR)
        return;

    int times = bR - aR;
    for (int i = 0; i < times; ++i)
    {
        int tmp = arr[aR * size + (aC + i)];
        arr[aR * size + (aC + i)] = arr[(bR - i) * size + aC];
        arr[(bR - i) * size + aC] = arr[bR * size + (bC - i)];
        arr[bR * size + (bC - i)] = arr[(aR + i) * size + bC];
        arr[(aR + i) * size + bC] = tmp;
    }
}

void rotateMatrix(int *arr, int size)
{
    if (arr == nullptr || size < 2)
        return;

    int aR = 0, aC = aR;
    int bR = size - 1, bC = bR;
    while (aR < bR)
    {
        rotateInCircle(arr, size, aR++, aC++, bR--, bC--);
    }
}


int main()
{
//    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    rotateMatrix(arr, sqrt(sizeof(arr) / sizeof(int)));
    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
    {
        cout << arr[i] << " ";
    }

    return 0;
}