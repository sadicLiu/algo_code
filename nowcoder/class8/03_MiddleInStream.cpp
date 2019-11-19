#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

// 数据流中的中位数

class Solution
{
public:
    void Insert(int num)
    {
        if (maxHeap.size() == 0 && minHeap.size() == 0)
            minHeap.push(num);
        else
        {
            if (num > minHeap.top())
                minHeap.push(num);
            else
                maxHeap.push(num);
        }

        if (abs(maxHeap.size() - minHeap.size()) > 1)
        {
            if (maxHeap.size() > minHeap.size())
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }

    double GetMedian()
    {
        double res = (maxHeap.size() == minHeap.size())
                     ? (maxHeap.top() + minHeap.top()) / 2.0
                     : (maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top());

        return res;
    }

private:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

int main()
{
    int a = 1, b = 2;
    cout << (a + b) / 2.0;

    return 0;
}
