#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int findPeak(vector<int> &A)
    {
        int res = -1;
        if (A.size() < 3)
            return res;
        int l = 1, r = A.size() - 2;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
                return mid;
            else if (A[mid] < A[mid - 1])
                r = mid - 1;
            else if (A[mid] < A[mid + 1])
                l = mid + 1;
        }

        return res;
    }
};