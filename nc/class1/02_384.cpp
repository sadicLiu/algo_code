#include <iostream>
#include <set>

using namespace std;

class Solution
{
public:
    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string &s)
    {
        int arr[256] = {0};
        int res = 0;
        for (int l = 0, r = 0; r < s.length(); r++)
        {
            while (arr[s.at(r)] == 1)
            {
                arr[s.at(l++)] = 0;
            }
            res = max(res, r - l + 1);
            arr[s.at(r)] = 1;
        }

        return res;
    }
};

int main()
{
    Solution s;
    string str = "an++--viaj";
    cout << s.lengthOfLongestSubstring(str);
}
