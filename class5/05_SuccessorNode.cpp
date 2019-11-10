#include "BinaryTreeUtils.h"
#include <iostream>

using namespace std;

// 在二叉树中找到一个节点的后继节点

NodeWithParent *getMostLeft(NodeWithParent *head)
{
    NodeWithParent *p = head;
    while (p->left != NULL)
        p = p->left;
    return p;
}

NodeWithParent *getSuccessor(NodeWithParent *node)
{
    if (NULL == node)
        return NULL;

    if (node->right != NULL)
        return getMostLeft(node->right);

    NodeWithParent *cur = node, *p = node->parent;
    while (p != NULL && p->left != cur)
    {
        cur = p;
        p = p->parent;
    }
    return p;
}

int main()
{
    NodeWithParent *root = new NodeWithParent(1);
    root->parent = NULL;
    root->left = NULL;

    root->left = new NodeWithParent(2);
    root->left->parent = root;
    root->right = new NodeWithParent(6);
    root->right->parent = root;

    root->left->left = new NodeWithParent(4);
    root->left->left->parent = root->left;
    NodeWithParent *n1 = new NodeWithParent(3);
    root->left->right = n1;
    n1->parent = root->left;

    root->left->left->left = new NodeWithParent(5);
    root->left->left->left->parent = root->left->left;

    root->right->left = new NodeWithParent(7);
    root->right->left->parent = root->right;

    root->right->right = new NodeWithParent(8);
    root->right->right->parent = root->right;

    NodeWithParent *n2 = new NodeWithParent(9);
    root->right->right->right = n2;
    n2->parent = root->right->right;

    NodeWithParent *tmp = getSuccessor(root);
    cout << tmp->value << endl;

    cout << (getSuccessor(n2) == nullptr) << endl;
    cout << (getSuccessor(n1)->value) << endl;


    return 0;
}
