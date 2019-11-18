#include <iostream>

using namespace std;

void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

// 0~index-1 已经是大根堆了, 插入index位置的元素, 重新调整成大根堆
void heapInsert(int *arr, int index) {
    while (arr[index] > arr[(index - 1) / 2]) {
        swap(arr, index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}

// 大根堆大小为heapSize, 现在index位置的元素发生了改变, 向下调整, 使其重新成为大根堆
// 这里只进行向下调整的原因是 index的改变是从堆顶开始的, 因此不存在index位置的元素比它的父节点大的情况
void heapify(int *arr, int index, int heapSize) {
    int left = 2 * index + 1;
    while (left < heapSize) {
        int largest = left + 1 < heapSize && arr[left + 1] > arr[left]
                      ? left + 1
                      : left;
        largest = arr[index] >= arr[largest] ? index : largest;
        if (largest == index)
            return;
        swap(arr, index, largest);
        index = largest;
        left = 2 * index + 1;
    }
}

void heapSort(int *arr, int length) {
    if (arr == nullptr || length < 2)
        return;

    // 建立大根堆
    for (int i = 0; i < length; ++i) {
        heapInsert(arr, i);
    }

    int heapSize = length;
    while (heapSize > 0) {
        swap(arr, 0, --heapSize);
        heapify(arr, 0, heapSize);
    }
}

int main() {
    int arr[] = {1, 4, 2, 3, 6, 5};
    heapSort(arr, sizeof(arr) / sizeof(int));

    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
