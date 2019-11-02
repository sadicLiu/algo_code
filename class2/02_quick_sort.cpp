#include <iostream>

using namespace std;

void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void partition(int *arr, int l, int r, int num, int *res) {
    int min = l - 1, max = r + 1, cur = l;
    while (cur < max) {
        if (arr[cur] < num) {
            swap(arr, ++min, cur++);
        } else if (arr[cur] == num) {
            cur++;
        } else {
            swap(arr, cur, --max);
        }
    }

    res[0] = min + 1, res[1] = max - 1;
}

void quick_sort_process(int *arr, int l, int r) {
    if (arr == nullptr || l >= r)
        return;

    int res[2];
    partition(arr, l, r, arr[r], res);
    quick_sort_process(arr, l, res[0] - 1);
    quick_sort_process(arr, res[1] + 1, r);
}

void quick_sort(int *arr, int length) {
    if (arr == nullptr || length < 2)
        return;

    quick_sort_process(arr, 0, length - 1);
}


int main() {
//    int arr[] = {3, 4, 1, 5, 6, 2, 8};
//    int arr[] = {5, 4, 3, 2, 1};
//    int arr[] = {1, 2, 3, 4, 5};
    int arr[] = {3, 2, 1, 5, 6, 4, 3, 9};
    quick_sort(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
