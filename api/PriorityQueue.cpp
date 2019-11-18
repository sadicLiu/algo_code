#include <iostream>
#include <queue>

using namespace std;

template<typename T>
void print_queue(T &q)
{
    while (!q.empty())
    {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

int main()
{
    // notes: 默认比较函数为less (operator是小于号<), 大顶堆
    std::priority_queue<int> q;
    for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
        q.push(n);

    print_queue(q);

    // notes: 使用比较函数greater (operator是大于号>), 小顶堆
    std::priority_queue<int, std::vector<int>, std::greater<int> > q2;
    for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
        q2.push(n);

    print_queue(q2);

    return 0;
}