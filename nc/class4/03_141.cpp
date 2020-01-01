#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int sqrt(int x)
    {
        if (x <= 0)
            return 0;

        int min = 1, max = x;
        int mid = min + (max - min) / 2;
        while (!valid(mid, x, max, min)) mid = min + (max - min) / 2;

        return mid;
    }

    bool valid(int mid, int x, int &max, int &min)
    {
        long res = (long)mid * (long)mid;
        long res2 = (long)(mid + 1) * (long)(mid + 1);
        bool valid = res <= x && res2 > x;

        if (!valid)
        {
            max = res > x ? mid - 1 : max;
            min = res < x ? mid + 1 : min;
        }

        return valid;
    }
};