#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {}
};

class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        TreeNode *root = NULL;
        if (nums.size() < 1 || nums.size() > 1000)
            return root;

        vector<TreeNode *> nodes;
        for (auto val: nums)
        {
            TreeNode *tmp = new TreeNode(val);
            nodes.push_back(tmp);
        }

        stack<int> myStack;
        for (int i = 0; i < nums.size(); i++)
        {
            int value = nums[i];
            while (!myStack.empty() && value > nums[myStack.top()])
            {
                int topIndex = myStack.top();
                myStack.pop();

                int left = myStack.empty() ? -1 : myStack.top();
                if (left == -1 || nums[i] < nums[left])
                    nodes[i]->left = nodes[topIndex];
                else  // right > left
                    nodes[left]->right = nodes[topIndex];
            }

            myStack.push(i);
        }

        while (!myStack.empty())
        {
            int topIndex = myStack.top();
            myStack.pop();

            int left = myStack.empty() ? -1 : myStack.top();
            if (left == -1)
                root = nodes[topIndex];
            else
                nodes[left]->right = nodes[topIndex];
        }

        return root;
    }
};