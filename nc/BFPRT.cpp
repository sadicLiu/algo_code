#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*notes:
 * BFPRT算法解决的问题是在一个无序数组中找到第k大/第k小的数
 * 并且时间复杂度为严格的O(n)
 *
 * 这道题可以用快排的partition方法来做，时间复杂度依概率收敛到O(n)
 * */

class Solution
{
public:
    // 在begin到end范围上求第k小的数
    int bfprt(vector<int> &nums, int begin, int end, int k)
    {
        // 求中位数数组的中位数时, 会一直递归下去, 直到中位数数组中只有一个元素, 这时返回这个元素
        if (begin == end) return nums[begin];

        int pivot = medianOfMedians(nums, begin, end);
        int pivotRange[2] = {-1, -1};
        partition(nums, begin, end, pivot, pivotRange);
        if (k >= pivotRange[0] && k <= pivotRange[1])
            return nums[k];
        else if (k < pivotRange[0])
            return bfprt(nums, begin, pivotRange[0] - 1, k);
        else
            return bfprt(nums, pivotRange[1] + 1, end, k);
    }

    // 每5个数分成一组，组内排序，拿出每组的中位数组成新数组，返回新数组的中位数
    int medianOfMedians(vector<int> &nums, int begin, int end)
    {
        int num = end - begin + 1;
        int offset = num % 5 == 0 ? 0 : 1;
        vector<int> midNums;
        for (int i = 0; i < num / 5 + offset; ++i)
        {
            int beginI = begin + i * 5;
            int endI = min(end, beginI + 4);
            sort(nums.begin() + beginI, nums.begin() + endI + 1);
            midNums.push_back(nums[beginI + (endI - beginI) / 2]);
        }

        return bfprt(midNums, 0, midNums.size() - 1, midNums.size() / 2);
    }

    void partition(vector<int> &nums, int begin, int end, int pivot, int *res)
    {
        int cur = begin;
        begin--;
        end++;
        while (cur < end)
        {
            if (nums[cur] < pivot)
                swap(nums, ++begin, cur++);
            else if (nums[cur] == pivot)
                cur++;
            else
                swap(nums, --end, cur);
        }

        res[0] = begin + 1;
        res[1] = end - 1;
    }

    void swap(vector<int> &nums, int i, int k)
    {
        int tmp = nums[i];
        nums[i] = nums[k];
        nums[k] = tmp;
    }
};

int main()
{
    vector<int> nums = {5, 4, 1, 2, 3};
    Solution solution;

    cout << solution.bfprt(nums, 0, nums.size() - 1, 3);

    return 0;
}