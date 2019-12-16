#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int trapRainWater(vector<int> &heights)
    {
        if (heights.size() < 3)
            return 0;

        int left = 0;
        int right = heights.size() - 1;
        int res = 0;
        while (left < right)
        {
            int minIndex = heights[left] <= heights[right] ? left : right;
            int nextIndex = minIndex == left ? left + 1 : right - 1;

            if (heights[minIndex] > heights[nextIndex])
            {
                res += heights[minIndex] - heights[nextIndex];
                heights[nextIndex] = heights[minIndex];
            }

            left = minIndex == left ? left + 1 : left;
            right = minIndex == right ? right - 1 : right;
        }

        return res;
    }
};