#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 做项目, 使利益最大化, 每次只能做一个项目
// cost: 每个项目投资的钱
// profit: 每个项目的利润
// m: 初始资金
// k: 最多做k个项目

class Project
{
public:
    int cost;
    int profit;

    Project(int cost, int profit)
    {
        this->cost = cost;
        this->profit = profit;
    }
};

struct CostComparator
{
    bool operator()(Project a, Project b)
    {
        return a.cost > b.cost;  // 根据项目的cost组建小顶堆
    }
};

struct ProfitComparator
{
    bool operator()(Project a, Project b)
    {
        return a.profit < b.profit;  // 根据项目的利润组建大顶堆
    }
};

template<typename T>
void printQueue(T &q)
{
    cout << "cost: ";
    while (!q.empty())
    {
        std::cout << q.top().cost << " ";
        q.pop();
    }
    std::cout << '\n';
}

int maxProfit(vector<Project> projects, int m, int k)
{
    priority_queue<Project, vector<Project>, CostComparator> costs;  // 所有项目按cost组成小顶堆
    priority_queue<Project, vector<Project>, ProfitComparator> profits;  // 所有项目按profit组成大顶堆

    for (auto p : projects)
        costs.push(p);

    int currentMoney = m;
    while (k > 0)
    {
        while (!costs.empty() && costs.top().cost <= currentMoney)
        {
            profits.push(costs.top());
            costs.pop();
        }

        if (profits.empty())
            return currentMoney;

        Project currentProj = profits.top();
        profits.pop();
        currentMoney += currentProj.profit;
        k--;
    }

    return currentMoney;
}


int main()
{
    vector<Project> projects =
            {Project(100, 10),
             Project(50, 5),
             Project(70, 10),
             Project(200, 30)};
    int m = 100;
    int k = 4;
    cout << maxProfit(projects, m, k) << endl;  // 125

    m = 200;
    k = 1;
    cout << maxProfit(projects, m, k) << endl;  // 230

    m = 100;
    k = 2;
    cout << maxProfit(projects, m, k) << endl;  // 120

    return 0;
}