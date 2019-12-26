#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &height)
    {
        int res = 0;
        if (height.size() < 1)
            return res;

        stack<int> myStack;
        for (int i = 0; i < height.size(); i++)
        {
            int curHeight = height[i];
            if (!myStack.empty() && curHeight < height[myStack.top()])
            {
                while (!myStack.empty() && curHeight < height[myStack.top()])
                    update(res, myStack, height, i);
            }

            myStack.push(i);
        }

        while (!myStack.empty())
            update(res, myStack, height, height.size());

        return res;
    }

    void update(int &res, stack<int> &myStack, vector<int> &height, int right)
    {
        int topIndex = myStack.top();
        myStack.pop();
        int left = myStack.empty() ? -1 : myStack.top();
        int area = (right - left - 1) * height[topIndex];
        res = area > res ? area : res;
    }
};
