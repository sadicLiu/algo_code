#include <iostream>

using namespace std;

void swap(int *arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void heapInsert(int *arr, int heapSize)
{
    int index = heapSize;
    while (arr[index] > arr[(index - 1) / 2])
    {
        swap(arr, index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}

void heapify(int *arr, int current, int heapSize)
{
    int left = 2 * current + 1;
    if (left >= heapSize)
        return;

    int largest = (left + 1 < heapSize) && arr[left + 1] > arr[left] ? left + 1 : left;
    largest = arr[largest] > arr[current] ? largest : current;
    if (largest == current)
        return;

    swap(arr, current, largest);
    current = largest;
    heapify(arr, current, heapSize);
}

void heapSort(int *arr, int length)
{
    if (nullptr == arr || length < 2)
        return;

    int heapSize = 0;
    while (heapSize < length)
        heapInsert(arr, heapSize++);

    while (heapSize > 0)
    {
        swap(arr, 0, --heapSize);
        heapify(arr, 0, heapSize);
    }
}

int main()
{
    int arr[] = {7, 1, 6, 2, 5};
    heapSort(arr, 5);

    for (int i = 0; i < 5; ++i)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
