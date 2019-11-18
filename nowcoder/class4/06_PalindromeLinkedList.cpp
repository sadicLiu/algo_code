#include <iostream>
#include "LinkedListUtils.h"

using namespace std;

// 判断一个链表是否是回文结构

Node *reverseList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *prev = nullptr, *cur = head, *next = head->next;
    while (cur != nullptr)
    {
        cur->next = prev;
        prev = cur;
        cur = next;
        if (next != nullptr)
            next = cur->next;
    }

    return prev;
}

bool isPalindrome(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;

    Node *slow = head, *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *reverseHead = reverseList(slow);
    slow = head, fast = reverseHead;
    while (slow->next != nullptr)
    {
        if (slow->value != fast->value)
        {
            return false;
        } else
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    reverseList(reverseHead);

    return true;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 1};
    Node *head = LinkedListUtils::createList(arr, 5);
    cout << isPalindrome(head) << endl;
//    LinkedListUtils::printList(head);

    int arr2[] = {1, 2, 3, 3, 3, 1};
    Node *head2 = LinkedListUtils::createList(arr2, 6);
    cout << isPalindrome(head2) << endl;
//    LinkedListUtils::printList(head2);

    return 0;
}