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

            // 等于的情况直接把下标往栈里放没关系, 因为结算栈中靠上的等于元素时, 它的面积计算结果虽然是错误的
            // 但是它下面的元素结算的结果肯定比它大, 所以这个错误结果不会成为最终结果
            if (myStack.empty() || curHeight >= height[myStack.top()])
                myStack.push(i);
            else if (curHeight < height[myStack.top()])
            {
                while (!myStack.empty() && curHeight < height[myStack.top()])
                {
                    int topIndex = myStack.top();
                    myStack.pop();
                    int down = myStack.empty() ? -1 : myStack.top();
                    int curArea = (i - down - 1) * height[topIndex];
                    res = curArea > res ? curArea : res;
                }

                myStack.push(i);
            }
        }

        while (!myStack.empty())
        {
            int topIndex = myStack.top();
            myStack.pop();
            int down = myStack.empty() ? -1 : myStack.top();
            int curArea = (height.size() - down - 1) * height[topIndex];
            res = curArea > res ? curArea : res;
        }

        return res;
    }
};
