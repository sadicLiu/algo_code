#include <iostream>

using namespace std;

/*pdf中例子八*/

int merge(int *arr, int l, int mid, int r) {
    int help[r - l + 1];
    int index = 0;
    int p1 = l, p2 = mid + 1;

    int small_sum = 0;
    while (p1 <= mid && p2 <= r) {
        small_sum += arr[p1] < arr[p2] ? arr[p1] * (r - p2 + 1) : 0;
        help[index++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    }
    while (p1 <= mid)
        help[index++] = arr[p1++];
    while (p2 <= r)
        help[index++] = arr[p2++];

    for (int i = 0; i < r - l + 1; ++i)
        arr[l + i] = help[i];

    return small_sum;
}

int merge_sort_process(int *arr, int l, int r) {
    if (l == r)
        return 0;

    int mid = (l + r) / 2;
    return merge_sort_process(arr, l, mid) +
           merge_sort_process(arr, mid + 1, r) +
           merge(arr, l, mid, r);
}

int small_sum(int *arr, int length) {
    if (arr == nullptr || length <= 1)
        return 0;

    return merge_sort_process(arr, 0, length - 1);
}

int main() {
    int arr[] = {1, 3, 4, 2, 5};
    cout << small_sum(arr, sizeof(arr) / sizeof(int));

    return 0;
}