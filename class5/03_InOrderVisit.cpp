#include "BinaryTreeUtils.h"
#include <iostream>
#include <stack>

using namespace std;

// 中序遍历非递归

void inOrderVisit(Node *root)
{
    if (root == nullptr)
        return;

    Node *cur = root;
    stack<Node *> stack;
    while (cur != nullptr || !stack.empty())
    {
        if (cur != nullptr)
        {
            stack.push(cur);
            cur = cur->left;
        } else
        {
            cur = stack.top();
            stack.pop();
            cout << cur->value << " ";
            cur = cur->right;
        }
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    inOrderVisit(root);

    return 0;
}
