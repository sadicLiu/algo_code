#include "LinkedListUtils.h"
#include <iostream>

using namespace std;

// 荷兰国旗问题链表版本

Node *partition(Node *head, int num)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *small = nullptr, *eq = nullptr, *big = nullptr;
    Node *pSmall = nullptr, *pEq = nullptr, *pBig = nullptr;
    Node *p = head;
    while (p != nullptr)
    {
        if (p->value < num)
        {
            if (small == nullptr)
            {
                small = p;
                pSmall = p;
            } else
            {
                pSmall->next = p;
                pSmall = pSmall->next;
            }
        } else if (p->value == num)
        {
            if (eq == nullptr)
            {
                eq = p;
                pEq = p;
            } else
            {
                pEq->next = p;
                pEq = pEq->next;
            }

        } else
        {
            if (big == nullptr)
            {
                big = p;
                pBig = p;
            } else
            {
                pBig->next = p;
                pBig = pBig->next;
            }
        }

        p = p->next;
    }

    Node *newHead = nullptr;
    Node *tmp = nullptr;
    if (small != nullptr)
    {
        newHead = small;
        tmp = pSmall;
    }

    if (eq != nullptr)
    {
        newHead = newHead == nullptr ? eq : newHead;
        if (tmp == nullptr)
        {
            tmp = pEq;
        } else
        {
            tmp->next = eq;
            tmp = pEq;
        }
    }

    if (big != nullptr)
    {
        newHead = newHead == nullptr ? big: newHead;
        if (tmp == nullptr)
        {
            tmp = pBig;
        } else {
            tmp->next = big;
            tmp = pBig;
        }
    }
    tmp->next = nullptr;

    return newHead;
}

int main()
{
    int arr[] = {3, 6, 5, 1, 7, 2};
    Node *head = LinkedListUtils::createList(arr, 6);
    int num = 5;

    head = partition(head, num);
    LinkedListUtils::printList(head);


    return 0;
}