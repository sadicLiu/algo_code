#include <iostream>

using namespace std;

/*
 * 归并排序:
 * 先将左半部分排好序, 再将右半部分排好序, 最后以外排的方式将两部分归并
 * */

void merge(int *arr, int l, int mid, int r)
{
    int help[r - l + 1];
    int p1 = l, p2 = mid + 1;
    int index = 0;

    while (p1 <= mid && p2 <= r)
    {
        help[index++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    }
    while (p1 <= mid)
    {
        help[index++] = arr[p1++];
    }
    while (p2 <= r)
    {
        help[index++] = arr[p2++];
    }

    for (int i = 0; i < r - l + 1; i++)
    {
        arr[l + i] = help[i];
    }
}

void merge_sort_process(int *arr, int l, int r)
{
    if (l == r)
        return;

    int mid = (l + r) / 2;
    merge_sort_process(arr, l, mid);
    merge_sort_process(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

void merge_sort(int *arr, int length)
{
    if (nullptr == arr || length <= 1)
        return;

    merge_sort_process(arr, 0, length - 1);
}

int main()
{
//    int arr[] = {3, 1, 5, 2, 6, 4};
//    int arr[] = {1, 2, 3, 4, 5, 6};
    int arr[] = {6, 5, 4, 3, 2, 1};
    int length = sizeof(arr) / sizeof(int);
    merge_sort(arr, length);

    for (int i = 0; i < length; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}





