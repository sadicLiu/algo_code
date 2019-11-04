#include <iostream>

using namespace std;

// 拷贝含有随机指针的链表

struct Node
{
    int value;
    Node *next;
    Node *random;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
        random = nullptr;
    }
};

Node *copyList(Node *head)
{
    if (head == nullptr)
        return head;

    Node *p = head;
    while (p != nullptr)
    {
        Node *tmp = p->next;
        Node *newNode = new Node(p->value);
        p->next = newNode;
        newNode->next = tmp;
        p = tmp;
    }

    p = head;
    while (p != nullptr)
    {
        p->next->random = p->random == nullptr ? nullptr : p->random->next;
        p = p->next->next;
    }

    p = head;
    Node *pNewHead = nullptr;
    Node *pNewEnd = nullptr;
    while (p != nullptr)
    {
        Node *tmp = p->next;
        p->next = tmp->next;
        p = tmp->next;
        if (pNewHead == nullptr)
        {
            pNewHead = tmp;
            pNewEnd = tmp;
        } else
        {
            pNewEnd->next = tmp;
            pNewEnd = pNewEnd->next;
        }
    }

    return pNewHead;
}

void printList(Node *head)
{
    Node *p = head;
    cout << "in order: ";
    while (p != nullptr)
    {
        cout << p->value << " ";
        p = p->next;
    }

    cout << endl << "random: ";
    p = head;
    while (p != nullptr)
    {
        string res = p->random == nullptr ? "null" : to_string(p->random->value);
        cout << res << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Node n1(1), n2(3), n3(6), n4(2);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    n1.random = &n2;
    n2.random = &n4;
    n3.random = nullptr;
    n4.random = &n3;

    Node *head = &n1;
//    printList(head);

    Node *newList = copyList(head);
    printList(newList);
    printList(head);



    return 0;
}