#include <iostream>
#include <vector>
#include <algorithm>

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
        return a.cost > b.cost;
    }
};

int maxProfit(Project *projects, int projectNum, int m, int k)
{
    for (int i = 0; i < projectNum; ++i)
    {
        cout << projects[i].cost << ": " << projects[i].profit << endl;
    }

    return 1;
}

void sortV(vector<Project> &proj)
{
    for (int i = 0; i < proj.size(); ++i)
    {
        cout << proj[i].cost << endl;
    }

    make_heap(proj.begin(), proj.begin(), CostComparator());

    for (int i = 0; i < proj.size(); ++i)
    {
        cout << proj[i].cost << endl;
    }
}

int main()
{
    vector<Project> projects = {Project(100, 10), Project(50, 5), Project(70, 10), Project(200, 30)};
    int m = 100;
    int k = 4;

//    cout << maxProfit(projects, 4, m, k) << endl;  // 125
    sortV(projects);
//    sort(projects.begin(), projects.end(), CostComparator());

    return 0;
}