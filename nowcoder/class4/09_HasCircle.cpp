#include "LinkedListUtils.h"
#include <iostream>

using namespace std;

// 判断链表中是否有环

bool hasCircle(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return false;

    Node *fast = head->next, *slow = head;
    while (fast != slow)
    {
        if (fast->next == nullptr || fast->next->next == nullptr)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    Node *head = LinkedListUtils::createList(arr, 4);
    cout << hasCircle(head) << endl;

    head->next->next->next->next = head->next;
    cout << hasCircle(head) << endl;

    return 0;
}