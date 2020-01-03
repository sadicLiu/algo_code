#include <iostream>
#include <vector>
#include <map>

using namespace std;

class SVNRepo
{
public:
    static bool isBadVersion(int k);
};

class Solution
{
public:
    /**
     * @param n: An integer
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n)
    {
        if (n <= 1)
            return n;

        int min = 1;
        int max = n;
        int mid;
        while (min <= max)
        {
            mid = min + (max - min) / 2;
            bool cur = SVNRepo::isBadVersion(mid);
            if (cur)
                if (!SVNRepo::isBadVersion(mid - 1)) return mid;
                else max = mid - 1;
            else min = mid + 1;
        }
    }
};