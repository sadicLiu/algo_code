#include "BinaryTreeUtils.h"
#include <iostream>
#include <stack>

using namespace std;

// 先序遍历非递归

void preOrderVisit(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node*> stack;
    stack.push(root);
    while (!stack.empty())
    {
        Node *cur = stack.top();
        stack.pop();
        cout << cur->value << " ";
        if (cur->right != nullptr)
            stack.push(cur->right);
        if (cur->left != nullptr)
            stack.push(cur->left);
    }
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
//    printTree(root);

    preOrderVisit(root);

    return 0;
}
