#include "BinaryTreeUtils.h"
#include <iostream>

using namespace std;

// 判断一棵二叉树是否为平衡二叉树

bool isBalance(Node *root, int &height)
{
    if (root == nullptr || root->left == nullptr && root->right == nullptr)
    {
        height = root == nullptr ? 0 : 1;
        return true;
    }

    int leftHeight = 0, rightHeight = 0;
    bool leftResult = isBalance(root->left, leftHeight);
    if (!leftResult)
        return false;

    bool rightResult = isBalance(root->right, rightHeight);
    if (!rightResult)
        return false;

    if (abs(leftHeight - rightHeight) > 1)
        return false;

    height = max(leftHeight, rightHeight) + 1;
    return true;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->right = new Node(6);
//    printTree(root);

    int height = 0;
    cout << isBalance(root, height) << endl;

    root->right->right->left = new Node(1);
    int height2 = 0;
    cout << isBalance(root, height2) << endl;

    return 0;
}