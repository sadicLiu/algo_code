#include "BinaryTreeUtils.h"
#include <iostream>

using namespace std;

// 判断一棵二叉树是否为搜索二叉树(二叉树中序遍历时, 节点依次升序)
bool isBSTree(Node *root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return true;

    bool left = isBSTree(root->left);
    bool right = isBSTree(root->right);
    if (!left || !right)
        return false;

    Node *p;
    int leftMax = INT32_MIN, rightMin = INT32_MAX;
    if (root->left != nullptr)
    {
        p = root->left;
        while (p->right != nullptr)
            p = p->right;
        leftMax = p->value;
    }

    if (root->right != nullptr)
    {
        p = root->right;
        while (p->left != nullptr)
            p = p->left;
        rightMin = p->value;
    }

    bool result = (root->value > leftMax && root->value < rightMin) ? true : false;
    return result;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    root->right = new Node(9);
    root->right->left = new Node(6);
    root->right->left->left = new Node(5);
    root->right->left->right = new Node(7);
    root->right->right = new Node(11);
//    printTree(root);

    cout << (isBSTree(root) ? "Is BS Tree" : "Not BS Tree") << endl;

    root->value = 2;
    cout << (isBSTree(root) ? "Is BS Tree" : "Not BS Tree") << endl;


    return 0;
}