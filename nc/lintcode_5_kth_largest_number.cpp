#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int kthLargestElement(int n, vector<int> &nums)
    {
        if (n < 1 || nums.size() < 1 || n > nums.size())
            throw "Invalid input";

        int k = nums.size() - n;
        return bfprt(nums, 0, nums.size() - 1, k);
    }

    int bfprt(vector<int> &nums, int begin, int end, int k)
    {
        if (begin == end) return nums[begin];

        int pivot = medianOfMedians(nums, begin, end);
        int range[2];
        partition(nums, begin, end, pivot, range);
        if (k >= range[0] && k <= range[1])
            return nums[k];
        else if (k < range[0])
            return bfprt(nums, begin, range[0] - 1, k);
        else
            return bfprt(nums, range[1] + 1, end, k);
    }

    int medianOfMedians(vector<int> &nums, int begin, int end)
    {
        int num = end - begin + 1;
        int offset = num % 5 == 0 ? 0 : 1;
        vector<int> midNums;
        for (int i = 0; i < num / 5 + offset; i++)
        {
            int left = begin + i * 5;
            int right = min(end, left + 4);
            sort(nums.begin() + left, nums.begin() + right + 1);
            midNums.push_back(nums[left + (right - left) / 2]);
        }

        return bfprt(midNums, 0, midNums.size() - 1, midNums.size() / 2);
    }

    void partition(vector<int> &nums, int begin, int end, int pivot, int *range)
    {
        int cur = begin;
        begin--, end++;
        while (cur < end)
        {
            if (nums[cur] < pivot)
                swap(nums, ++begin, cur++);
            else if (nums[cur] == pivot)
                cur++;
            else
                swap(nums, --end, cur);
        }

        range[0] = begin + 1;
        range[1] = end - 1;
    }

    void swap(vector<int> &nums, int m, int n)
    {
        int tmp = nums[m];
        nums[m] = nums[n];
        nums[n] = tmp;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 3, 4, 2};

    cout << solution.bfprt(nums, 0, nums.size() - 1, 3);
    sort(nums.begin(), nums.end(), greater<int>());

    return 0;
}