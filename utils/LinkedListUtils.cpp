//
// Created by liuhy on 2019/11/4.
//

#include "LinkedListUtils.h"

Node *LinkedListUtils::createList(int *arr, int length)
{
    Node *head = nullptr;
    Node *p = head;
    for (int i = 0; i < length; ++i)
    {
        Node *tmp = new Node(arr[i]);
        if (head == nullptr)
        {
            head = tmp;
            p = tmp;
        } else
        {
            p->next = tmp;
            p = tmp;
        }
    }

    return head;
}

void LinkedListUtils::printList(Node *head)
{
    if (head == nullptr)
        return;

    Node *p = head;
    while (p != nullptr)
    {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}
