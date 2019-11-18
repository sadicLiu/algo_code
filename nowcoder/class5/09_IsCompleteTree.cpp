#include "BinaryTreeUtils.h"
#include <iostream>
#include <queue>

using namespace std;

// 判断一棵二叉树是否为完全二叉树

bool isCompleteTree(Node *root)
{
    // 按层遍历: 1.有右无左,false  2.有左无右,后面的节点必须都是叶节点
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return true;

    bool flag = false;

    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        Node *tmp = que.front();
        que.pop();

        if (tmp->right != nullptr && tmp->left == nullptr)
            return false;

        bool isLeaf = tmp->left == nullptr && tmp->right == nullptr;
        if (!isLeaf && flag)
            return false;
        if (!isLeaf && tmp->right == nullptr)
        {
            flag = true;
            que.push(tmp->left);
        }
        if (!isLeaf && tmp->right != nullptr)
        {
            que.push(tmp->left);
            que.push(tmp->right);
        }
    }

    return true;
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
//    printTree(root);

    cout << (isCompleteTree(root) ? "Yes" : "No") << endl;  // Yes

    root->left->left->left = new Node(8);
    cout << (isCompleteTree(root) ? "Yes" : "No") << endl;  // Yes

    root->right->right->right = new Node(10);
    cout << (isCompleteTree(root) ? "Yes" : "No") << endl;  // No

    return 0;
}