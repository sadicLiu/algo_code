//
// Created by liuhy on 2019/11/4.
//

#ifndef CODE_CPP_LINKEDLISTUTILS_H
#define CODE_CPP_LINKEDLISTUTILS_H

#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

class LinkedListUtils
{
public:
    static Node *createList(int *arr, int length);

    static void printList(Node *head);
};


#endif //CODE_CPP_LINKEDLISTUTILS_H
