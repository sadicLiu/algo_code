#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k)
    {
        if (s.size() == 0 || k < 1)
            return 0;

        int j = 0;
        int maxLength = 0;
        map<char, int> hash;
        for (int i = 0; i < s.length(); i++)
        {
            while (j < s.length() && hash.size() <= k)
            {
                if (hash.size() == k && hash.find(s.at(j)) == hash.end())
                    break;

                int count = hash.find(s.at(j)) == hash.end() ? 1 : hash[s.at(j)] + 1;
                hash[s.at(j++)] = count;
            }

            maxLength = max(maxLength, j - i);
            if (hash[s.at(i)] == 1)
                hash.erase(s.at(i));
            else
                hash[s.at(i)]--;
        }

        return maxLength;
    }

};

int main()
{
    map<char, int> map;
    map.emplace('a', 1);
    map.emplace('b', 2);

    cout << "size: " << map.size() << endl;

    cout << (map['c'] == 0 ? "true" : "false") << endl;

    cout << "size: " << map.size() << endl;
}
