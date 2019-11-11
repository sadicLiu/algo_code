#include <iostream>
#include <BinaryTreeUtils.h>
#include <cmath>

using namespace std;

// 已知一棵完全二叉树, 求其节点个数, 要求时间复杂度低于O(n)

int getHeight(Node *root)
{
    int height = 0;
    Node *p = root;
    while (p != nullptr)
    {
        height++;
        p = p->left;
    }

    return height;
}

int getNodeNumber(Node *root)
{
    if (root == nullptr)
        return 0;

    int height = getHeight(root);
    int rightHeight = getHeight(root->right);
    if (rightHeight == height - 1)  // 左子树为完全二叉树
    {
        return pow(2, height - 1) + getNodeNumber(root->right);
    } else  // rightHeight == height - 2, 右子树为完全二叉树
    {
        return pow(2, rightHeight) + getNodeNumber(root->left);
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
//    printTree(root);

    cout << getNodeNumber(root) << endl;

    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    cout << getNodeNumber(root) << endl;

    return 0;
}