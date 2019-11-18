#include "BinaryTreeUtils.h"
#include <iostream>
#include <stack>

using namespace std;

// 后序遍历非递归

void postOrderVisit(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> nodes;
    stack<int> result;
    nodes.push(root);
    while (!nodes.empty())
    {
        Node *cur = nodes.top();
        nodes.pop();
        result.push(cur->value);

        if (cur->left != nullptr)
            nodes.push(cur->left);
        if (cur->right != nullptr)
            nodes.push(cur->right);
    }

    while (!result.empty())
    {
        cout << result.top() << " ";
        result.pop();
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

    postOrderVisit(root);

    return 0;
}
