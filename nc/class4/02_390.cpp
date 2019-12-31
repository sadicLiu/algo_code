#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> findPeakII(vector<vector<int>> nums)
    {
        vector<int> res;
        if (nums.size() < 3 || nums[0].size() < 3)
            return res;

        process(nums, res, 0, nums.size() - 1, true);
        return res;
    }

    void process(vector<vector<int>> &nums, vector<int> &res, int start, int end, bool top)
    {
        int maxCol = 0;
        int mid = (end - start < 2) ? (top ? end : start) : (start + (end - start) / 2);
        for (int i = 1; i < nums[0].size(); i++) maxCol = nums[mid][maxCol] > nums[mid][i] ? maxCol : i;

        if ((end - start < 2) ||
            (nums[mid][maxCol] > nums[mid - 1][maxCol] && nums[mid][maxCol] > nums[mid + 1][maxCol]))
        {
            res.push_back(mid);
            res.push_back(maxCol);
        } else if (nums[mid][maxCol] < nums[mid - 1][maxCol])
        {
            process(nums, res, start, mid - 1, true);
        } else if (nums[mid][maxCol] < nums[mid + 1][maxCol])
        {
            process(nums, res, mid + 1, end, false);
        }
    }
};

/*
int main()
{
    vector<vector<int>> nums = {{1,  2,  3,  6,  5},
                                {16, 21, 20, 22, 6},
                                {15, 17, 22, 21, 7},
                                {14, 48, 24, 20, 10},
                                {13, 14, 11, 10, 9}};

    Solution solution;
    vector<int> res = solution.findPeakII(nums);
    cout << res[0] << endl;
    cout << res[1] << endl;

    return 0;
}*/
