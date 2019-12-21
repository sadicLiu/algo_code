#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<int> medianII(vector<int> &nums)
    {
        vector<int> res;
        if (nums.size() == 0)
            return res;

        for (int i = 0; i < nums.size(); ++i)
        {
            int cur = nums[i];
            if (minHeap.size() == 0 || maxHeap.size() == 0)
                maxHeap.push(cur);
            else
            {
                if (cur > minHeap.top())
                    minHeap.push(cur);
                else
                    maxHeap.push(cur);
            }

            int sub = minHeap.size() - maxHeap.size();
            if (abs((int)(minHeap.size() - maxHeap.size())) > 1)
            {
                if (minHeap.size() > maxHeap.size())
                {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                } else
                {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }
            }

            int mid = maxHeap.size() == minHeap.size() ? maxHeap.top()
                                                       : maxHeap.size() > minHeap.size() ? maxHeap.top()
                                                                                         : minHeap.top();
            res.push_back(mid);
        }
    }

private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
};

/*
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    s.medianII(nums);

    return 0;
}*/
