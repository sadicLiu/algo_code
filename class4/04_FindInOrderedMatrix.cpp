#include <iostream>

using namespace std;

// 在行和列都排好序的矩阵中找数

bool findNumber(int *arr, int rows, int cols, int num)
{
    if (arr == nullptr || rows < 1 || cols < 1)
        return false;

    int r = 0, c = cols - 1;
    while (c >= 0 && r < rows)
    {
        if (arr[r * cols + c] == num)
            return true;
        else if (arr[r * cols + c] > num)
            c--;
        else
            r++;
    }

    return false;
}

int main()
{
    int arr[] = {0, 1, 2, 5, 2, 3, 4, 7, 4, 4, 4, 8, 5, 7, 7, 9};
    int rows = 4, cols = 4;
    cout << findNumber(arr, 4, 4, 7) << endl;
    cout << findNumber(arr, 4, 4, 6) << endl;

    return 0;
}