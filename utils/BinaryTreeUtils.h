#ifndef CODE_CPP_BINARYTREEUTILS_H
#define CODE_CPP_BINARYTREEUTILS_H

#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;

    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

struct NodeWithParent
{
    int value;
    NodeWithParent *parent;
    NodeWithParent *left;
    NodeWithParent *right;

    NodeWithParent(int value)
    {
        this->value = value;
        this->parent = NULL;
        this->left = NULL;
        this->right = NULL;
    }
};

void printTree(Node *root);

#endif //CODE_CPP_BINARYTREEUTILS_H
