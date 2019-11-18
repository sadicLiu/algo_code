#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int cost;
    int profit;

    Node(int c, int p) : cost(c), profit(p)
    {}

    // notes: 方法1, 在类内实现, 最后必须加const
    bool operator<(const Node &node) const
    {
        return this->cost < node.cost;
    }
};

// notes: 方法2, 定义全局函数实现
bool operator>(const Node &a, const Node &b)
{
    return a.profit > b.profit;         //小顶堆
}

//notes: 方法3, 定义比较器类实现, 这种方法对于不同成员变量排序的情况更合适
struct MinHeapCostComparator
{
    bool operator()(Node a, Node b)
    {
        return a.cost > b.cost;  //小顶堆
    }
};

template<typename T>
void printQueue(T &q)
{
    while (!q.empty())
    {
        std::cout << q.top().cost << " ";
        q.pop();
    }
    std::cout << '\n';
}

int main()
{
    std::priority_queue<Node, vector<Node>, less<Node>> q;  // 默认是大根堆
    q.push(Node(100, 10));
    q.push(Node(50, 5));
    q.push(Node(70, 5));
    q.push(Node(200, 30));

//    printQueue(q);

    priority_queue<Node, vector<Node>, greater<Node>> q2;
    q2.push(Node(100, 10));
    q2.push(Node(50, 5));
    q2.push(Node(70, 1));
    q2.push(Node(200, 30));

//    printQueue(q2);

    priority_queue<Node, vector<Node>, MinHeapCostComparator> q3;
    q3.push(Node(100, 10));
    q3.push(Node(50, 5));
    q3.push(Node(70, 5));
    q3.push(Node(200, 30));
    printQueue(q3);


    return 0;
}