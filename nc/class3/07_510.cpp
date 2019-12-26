#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<bool>> &matrix)
    {
        int res = 0;
        if (matrix.size() < 1 || matrix[0].size() < 1)
            return res;

        vector<int> height;
        for (int r = 0; r < matrix.size(); r++)
        {
            for (int c = 0; c < matrix[0].size(); c++)
            {
                if (r == 0)
                    height.push_back(matrix[r][c]);
                else
                    height[c] = matrix[r][c] == 0 ? 0 : height[c] + matrix[r][c];
            }

            int curArea = maxArea(height);
            res = curArea > res ? curArea : res;
        }

        return res;
    }

    int maxArea(vector<int> &height)
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