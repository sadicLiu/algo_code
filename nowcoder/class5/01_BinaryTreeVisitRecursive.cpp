#include "BinaryTreeUtils.h"
#include <iostream>

using namespace std;

// 递归遍历二叉树, 前序, 中序, 后序

void preOrderVisit(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->value << " ";
    preOrderVisit(root->left);
    preOrderVisit(root->right);
}

void inOrderVisit(Node *root)
{
    if (root == nullptr)
        return;
    inOrderVisit(root->left);
    cout << root->value << " ";
    inOrderVisit(root->right);
}

void postOrderVisit(Node *root)
{
    if (root == nullptr)
        return;
    postOrderVisit(root->left);
    postOrderVisit(root->right);
    cout << root->value << " ";
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
//    printTree(root);

    preOrderVisit(root);
    cout << endl;

    inOrderVisit(root);
    cout << endl;

    postOrderVisit(root);
    cout << endl;

    return 0;
}
