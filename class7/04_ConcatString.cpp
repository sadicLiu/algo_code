#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string s1, const string s2)
{
    return (s1 + s2) < (s2 + s1);
}

int main()
{
    string s1 = "b";
    string s2 = "bc";
    string s3 = "ab";
    vector<string> strings;
    strings.push_back(s1);
    strings.push_back(s2);
    strings.push_back(s3);
    sort(strings.begin(), strings.end(), compare);

    for (int i = 0; i < strings.size(); ++i)
    {
        cout << strings[i] << endl;
    }



    return 0;
}