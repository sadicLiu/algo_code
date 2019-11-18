#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 一块金条切成两半,是需要花费和长度数值一样的铜板的. 比如长度为20的金条,
// 不管切成长度多大的两半,都要花费20个铜板. 一群人想分整块金条,怎么分最省铜板?

int lessMoney(vector<int> &goldens)
{
    if (goldens.size() <= 1)
        return 0;

    int money = 0;
    make_heap(goldens.begin(), goldens.end(), greater<int>());
    while (goldens.size() > 1)
    {
        pop_heap(goldens.begin(), goldens.end(), greater<int>());
        int v1 = goldens.back();
        goldens.pop_back();
        pop_heap(goldens.begin(), goldens.end(), greater<int>());
        int v2 = goldens.back();
        goldens.pop_back();

        int tmp = v1 + v2;
        money += tmp;
        goldens.push_back(tmp);
        push_heap(goldens.begin(), goldens.end());
    }

    return money;
}

int main()
{
//    vector<int> goldens{10, 20, 30};
    vector<int> goldens{100, 100, 300, 50};
    cout << lessMoney(goldens) << endl;

    return 0;
}