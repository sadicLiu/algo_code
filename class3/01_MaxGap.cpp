#include <iostream>
#include <cstring>

using namespace std;

// 数组中相邻两数的最大差值

int getBucketIndex(int min, int max, int n, int value) {
    // 等价于 (value - min) / ((max - min + 1) / (n + 1))
    // 第二项代表的是每个桶里可以放多少个数
    return (value - min) * (n + 1) / (max - min + 1);
}

int maxGap(int *arr, int length) {
    if (arr == nullptr || length < 2)
        return 0;

    int min = INT32_MAX, max = INT32_MIN;
    for (int i = 0; i < length; i++) {
        min = arr[i] < min ? arr[i] : min;
        max = arr[i] > max ? arr[i] : max;
    }
    if (min == max)
        return 0;

    bool hasNum[length + 1];
    memset(hasNum, 0, sizeof(bool) * (length + 1));
    int mins[length + 1], maxs[length + 1];
    for (int j = 0; j < length; ++j) {
        int bucketIndex = getBucketIndex(min, max, length, arr[j]);
        if (hasNum[bucketIndex]) {
            mins[bucketIndex] = mins[bucketIndex] < arr[j] ? mins[bucketIndex] : arr[j];
            maxs[bucketIndex] = maxs[bucketIndex] > arr[j] ? maxs[bucketIndex] : arr[j];
        } else {
            hasNum[bucketIndex] = true;
            mins[bucketIndex] = arr[j];
            maxs[bucketIndex] = arr[j];
        }
    }

    int res = 0, lastMax = maxs[0];
    for (int k = 1; k <= length; ++k) {
        if (hasNum[k]) {
            int gap = mins[k] - lastMax;
            res = res > gap ? res : gap;
            lastMax = maxs[k];
        }
    }

    return res;
}


int main() {

    int arr[] = {1, 3, 10, 6, 2, 5};
//    int arr[] = {0, 99, 10, 29, 39, 49, 59, 69, 79, 89};
    cout << maxGap(arr, sizeof(arr) / sizeof(int)) << endl;

    return 0;
}
