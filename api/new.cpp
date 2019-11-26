#include <iostream>

using namespace std;

int main()
{
    int *arr = new int[10];  // 未初始化
    int *arr2 = new int[10]();  // 所有元素初始化为默认值0
    int *arr3 = new int[10]{1, 2, 3};  // 1,2,3,0,0,...

    for (int i = 0; i < 10; ++i)
    {
        cout << arr3[i] << " ";
    }

    delete[](arr, arr2, arr3);

    return 0;
}