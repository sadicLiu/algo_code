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

void printTree(Node *root);

#endif //CODE_CPP_BINARYTREEUTILS_H
