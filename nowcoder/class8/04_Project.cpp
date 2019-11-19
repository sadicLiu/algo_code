#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 一些项目要占用一个会议室宣讲,会议室不能同时容纳两个项目的宣讲。
// 给你每一个项目开始的时间和结束的时间(给你一个数组,里面是一个个具体的项目),
// 你来安排宣讲的日程,要求会议室进行的宣讲的场次最多。返回这个最多的宣讲场次。

struct Project
{
    int start;
    int end;

    Project(int s, int e) : start(s), end(e)
    {}
};

struct ProjectCmp
{
    bool operator()(Project a, Project b)
    {
        return a.end < b.end;
    }
};

int maxProjNum(vector<Project> &projs)
{
    if (projs.size() < 2)
        return projs.size();

    int res = 1;
    sort(projs.begin(), projs.end(), ProjectCmp());

    int lastEnd = projs[0].end;
    for (int i = 1; i < projs.size(); ++i)
    {
        if (projs[i].start > lastEnd)
        {
            res++;
            lastEnd = projs[i].end;
        }
    }

    return res;
}


int main()
{
    vector<Project> projs =
            {Project(1, 3), Project(2, 5), Project(4, 7), Project(1, 8)};
    cout << maxProjNum(projs) << endl;

    return 0;
}