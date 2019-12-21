#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

/*这里使用multiset实现*/

class Solution
{
public:
    vector<int> medianSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        if (nums.size() == 0 || k < 1 || nums.size() < k)
            return res;
        if (k == 1)
        {
            res.assign(nums.begin(), nums.end());
            return res;
        }

        multiset<int> maxHeap, minHeap;
        for (int i = 0; i < k; ++i)
            maxHeap.insert(nums[i]);
        for (int j = 0; j < k / 2; ++j)
        {
            minHeap.insert(*maxHeap.rbegin());
            maxHeap.erase(maxHeap.lower_bound(*maxHeap.rbegin()));
        }

        res.push_back(*maxHeap.rbegin());
        for (int l = k; l < nums.size(); ++l)
        {
            if (nums[l - k] > *maxHeap.rbegin())
            {
                minHeap.erase(minHeap.lower_bound(nums[l - k]));
                minHeap.insert(nums[l]);
            } else
            {
                maxHeap.erase(maxHeap.lower_bound(nums[l - k]));
                maxHeap.insert(nums[l]);
            }

            if (*maxHeap.rbegin() > *minHeap.begin())
            {
                int tmp = *minHeap.begin();
                minHeap.erase(minHeap.lower_bound(tmp));
                minHeap.insert(*maxHeap.rbegin());
                maxHeap.erase(maxHeap.lower_bound(*maxHeap.rbegin()));
                maxHeap.insert(tmp);
            }

            res.push_back(*maxHeap.rbegin());
        }

        return res;
    }
};
