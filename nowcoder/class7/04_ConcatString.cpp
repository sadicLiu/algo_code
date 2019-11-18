#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 给定一些字符串, 将他们拼接成一个字符串,

bool compare(const string s1, const string s2)
{
    return (s1 + s2) < (s2 + s1);
}

string concatString(vector<string> &strs)
{
    sort(strs.begin(), strs.end(), compare);

    string res = "";
    for (int i = 0; i < strs.size(); ++i)
    {
        res += strs[i];
    }

    return res;
}

int main()
{
    vector<string> strs;
    strs.push_back("b");
    strs.push_back("ba");
    cout << concatString(strs) << endl;

    strs.clear();
    strs.push_back("ab");
    strs.push_back("ac");
    strs.push_back("ba");
    cout << concatString(strs) << endl;

    return 0;
}