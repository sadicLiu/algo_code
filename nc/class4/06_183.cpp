#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

class Solution
{
public:
    /**
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &L, int k)
    {
        long long res = 0;
        if (L.size() == 0 || k < 1) return res;
        int min = 0, max = INT_MIN;
        for (auto l: L)
        {
            res += l;
            max = l > max ? l : max;
        }

        if (res < k) return 0;
        res = 0;

        while (min <= max)
        {
            int mid = min + (max - min) / 2;
            int num = 0;
            for (auto l: L) num += l / mid;

            if (num >= k)
            {
                res = mid > res ? mid : res;
                min = mid + 1;
            } else
            {
                max = mid - 1;
            }
        }

        return res;
    }
};