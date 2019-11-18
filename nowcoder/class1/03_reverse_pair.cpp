#include <iostream>

using namespace std;

void merge(int *arr, int l, int mid, int r) {
    int help[r - l + 1];
    int index = 0;
    int p1 = l, p2 = mid + 1;

    while (p1 <= mid && p2 <= r) {
        if (arr[p1] <= arr[p2]) {
            help[index++] = arr[p1++];
        } else {
            for (int i = p1; i <= mid; ++i)
                cout << "pair: (" << arr[i] << "," << arr[p2] << ")" << endl;
            help[index++] = arr[p2++];
        }
    }
    while (p1 <= mid)
        help[index++] = arr[p1++];
    while (p2 <= r)
        help[index++] = arr[p2++];

    for (int j = 0; j < r - l + 1; ++j)
        arr[l + j] = help[j];
}

void merge_sort(int *arr, int l, int r) {
    if (l == r)
        return;

    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

void reverse_pair(int *arr, int length) {
    if (arr == nullptr || length <= 1)
        return;

    merge_sort(arr, 0, length - 1);
}

int main() {
    int arr[] = {3, 2, 1, 6, 5};
    reverse_pair(arr, sizeof(arr) / sizeof(int));

    return 0;
}