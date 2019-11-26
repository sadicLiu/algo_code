#include <iostream>

using namespace std;

class Solution
{
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source, string &target)
    {
        if (source.size() == 0 || target.size() == 0)
            return "";

        int targetArr[256] = {0};
        int srcArr[256] = {0};

        buildTarget(target, targetArr);

        string res;
        int l = 0, r = 0;
        for (; l < source.size(); l++)
        {
            while (!valid(srcArr, targetArr) && r < source.size())
            {
                srcArr[source.at(r++)]++;
            }

            if (valid(srcArr, targetArr))
            {
                string tmp = source.substr(l, r - l);
                res = res.size() == 0 ? tmp : (tmp.size() < res.size() ? tmp : res);
            }

            srcArr[source.at(l)]--;
        }

        return res;
    }

private:
    void buildTarget(string &target, int *arr)
    {
        for (int i = 0; i < target.size(); ++i)
        {
            arr[target.at(i)]++;
        }
    }

    bool valid(int *src, int *target)
    {
        for (int i = 0; i < 256; ++i)
        {
            if (src[i] < target[i])
                return false;
        }

        return true;
    }
};