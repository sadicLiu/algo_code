#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printContainer(vector<int> vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int test()
{
    vector<int> v1{6, 1, 2, 5, 3, 4};
    make_heap(v1.begin(), v1.end());
    printContainer(v1);

    v1.push_back(200);
    printContainer(v1);

    push_heap(v1.begin(), v1.end());
    printContainer(v1);

    pop_heap(v1.begin(), v1.end(), less<int>());
    printContainer(v1);
    auto largest = v1.back();
    cout << largest << endl;
    v1.pop_back();
    printContainer(v1);

    return 0;
}