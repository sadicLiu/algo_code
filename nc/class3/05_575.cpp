#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution
{
public:
    string expressionExpand(string &s)
    {
        if (s.size() < 2)
            return s;

        string res = "";
        stack<string> stack;
        for (int i = 0; i < s.size(); i++)
        {
            string ch(&s.at(i), 1);
            if (ch == "[")
            {
                continue;
            } else if (ch == "]")
            {
                string tmp = "";
                while (!stack.empty())
                {
                    string cur = stack.top();
                    stack.pop();
                    if (isDigit(cur))
                    {
                        int times = stoi(cur);  // times == 0 注意处理
                        string src = tmp;
                        for (int t = 0; t < times - 1; t++)
                            tmp += src;

                        if (stack.empty())
                            res = times == 0 ? res : res + tmp;
                        else if (times > 0)
                            stack.push(tmp);

                        break;
                    } else
                    {
                        tmp = cur + tmp;
                    }
                }
            } else if (isDigit(ch))
            {
                string curNum = ch;
                for (int r = i + 1; r < s.size(); r++)
                {
                    string nextCh = string(&s[r], 1);
                    if (isDigit(nextCh))
                        curNum += nextCh;
                    else
                    {
                        i = r - 1;
                        break;
                    }
                }
                stack.push(curNum);
            } else  // 当前字符是字母
            {
                if (stack.empty())
                    res += ch;
                else
                    stack.push(ch);
            }
        }

        return res;
    }

    bool isDigit(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] < '0' || s[i] > '9')
                return false;
        }

        return true;
    }
};