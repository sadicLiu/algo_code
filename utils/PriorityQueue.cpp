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
    std::priority_queue<int> q;  // 默认是大根堆
    for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
        q.push(n);

    print_queue(q);

    std::priority_queue<int, std::vector<int>, std::greater<int> > q2;
    for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
        q2.push(n);

    print_queue(q2);

    return 0;
}