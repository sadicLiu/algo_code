#include <iostream>

using namespace std;

void merge(int *arr, int left, int mid, int right)
{
    int help[right - left + 1];
    int p1 = left, p2 = mid + 1;
    int index = 0;

    while (p1 <= mid && p2 <= right)
        help[index++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    while (p1 <= mid)
        help[index++] = arr[p1++];
    while (p2 <= right)
        help[index++] = arr[p2++];

    for (int i = 0; i < right - left + 1; ++i)
        arr[left + i] = help[i];
}

void mergeSortCore(int *arr, int left, int right)
{
    if (left == right)
        return;

    int mid = (left + right) / 2;
    mergeSortCore(arr, left, mid);
    mergeSortCore(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSort(int *arr, int length)
{
    if (arr == nullptr || length < 2)
        return;

    mergeSortCore(arr, 0, length - 1);
}

int main()
{
    int arr[] = {7, 8, 1, 4, 5, 3, 11, 99};
    mergeSort(arr, sizeof(arr) / sizeof(int));

    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
    {
        cout << arr[i] << " ";
    }

    return 0;
}