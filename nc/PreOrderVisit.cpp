#include <iostream>
#include <stack>
#include "BinaryTreeUtils.h"


using namespace std;

void preOrderVisitRecursive(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->value << " ";
    preOrderVisitRecursive(root->left);
    preOrderVisitRecursive(root->right);
}

void preOrderVisit(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> nodes;
    nodes.push(root);
    while (!nodes.empty())
    {
        Node *cur = nodes.top();
        nodes.pop();
        cout << cur->value << " ";

        if (cur->right != nullptr)
            nodes.push(cur->right);
        if (cur->left != nullptr)
            nodes.push(cur->left);
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
    printTree(root);

    preOrderVisitRecursive(root);
    cout << endl;

    preOrderVisit(root);
    cout << endl;

    return 0;
}