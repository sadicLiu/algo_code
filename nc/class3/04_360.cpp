#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

/*使用优先级队列实现, 时间复杂度太高, 无法通过, 应该是删除元素的问题*/

class Solution
{
public:
    vector<int> medianSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        if (nums.size() < k || k < 1)
            return res;
        if (k == 1)
        {
            res.assign(nums.begin(), nums.end());
            return res;
        }

        for (int i = 0; i < k; ++i)
            add(nums[i]);
        res.push_back(getMiddle(k));

        for (int j = k; j < nums.size(); ++j)
        {
            remove(nums[j - k]);
            add(nums[j]);
            res.push_back(getMiddle(k));
        }

        return res;
    }

private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;

    void adjustSize()
    {
        int sub = maxHeap.size() - minHeap.size();
        if (abs(sub) > 1)
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

    void add(int num)
    {
        if (minHeap.size() == 0 || maxHeap.size() == 0)
        {
            maxHeap.push(num);
            if (minHeap.size() > 0)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        } else
        {
            if (num > minHeap.top())
                minHeap.push(num);
            else
                maxHeap.push(num);
        }

        adjustSize();
    }

    void remove(int num)
    {
        vector<int> tmp;
        if (num >= minHeap.top())
        {
            while (!minHeap.empty())
            {
                int top = minHeap.top();
                minHeap.pop();
                if (top == num)
                    break;

                tmp.push_back(top);
            }

            for (int i = 0; i < tmp.size(); ++i)
            {
                minHeap.push(tmp[i]);
            }
        } else
        {
            while (!maxHeap.empty())
            {
                int top = maxHeap.top();
                maxHeap.pop();
                if (top == num)
                    break;

                tmp.push_back(top);
            }

            for (int i = 0; i < tmp.size(); ++i)
            {
                maxHeap.push(tmp[i]);
            }
        }

        adjustSize();
    }

    int getMiddle(int k)
    {
        if (k % 2 == 0)
            return maxHeap.top();
        else
            return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
    }
};