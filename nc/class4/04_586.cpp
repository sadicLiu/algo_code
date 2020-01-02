#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    double sqrt(double x)
    {
        double start = 0.0;
        double end = x;
        double eps = 1e-8;

        if (x < 1.0) end = 1.0;

        double mid;
        while (end - start > eps)
        {
            mid = start + (end - start) / 2;
            if (mid * mid < x) start = mid;
            else end = mid;
        }

        return mid;
    }
};