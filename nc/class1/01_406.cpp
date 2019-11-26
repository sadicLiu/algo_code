#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * @param nums: an array of integers
     * @param s: An integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s)
    {
        if (nums.size() == 0)
            return -1;

        int sum = 0;
        int res = INT32_MAX;
        for (int l = 0, r = 0; r < nums.size(); ++r)
        {
            sum += nums[r];
            while (sum >= s)
            {
                res = min(res, r - l + 1);
                sum -= nums[l++];
            }
        }

        return (res == INT32_MAX) ? -1 : res;
    }
};
