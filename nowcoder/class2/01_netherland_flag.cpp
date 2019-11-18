#include <iostream>

using namespace std;

void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void partition(int *arr, int l, int r, int num, int *result) {
    if (nullptr == arr || l == r)
        return;

    int cur = l, min = l - 1, max = r + 1;
    while (cur < max) {
        if (arr[cur] < num) {
            swap(arr, ++min, cur++);
        } else if (arr[cur] == num) {
            cur++;
        } else {
            swap(arr, cur, --max);
        }
    }

    result[0] = min + 1, result[1] = max - 1;
}

int main() {
    int arr[] = {3, 6, 9, 1, 5, 5, 4, 7, 8};
    int result[2] = {-1, -1};

    partition(arr, 0, sizeof(arr) / sizeof(int) - 1, 5, result);
    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << result[0] << ", " << result[1];

    return 0;
}
