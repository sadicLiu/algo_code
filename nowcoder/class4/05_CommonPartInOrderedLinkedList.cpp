#include <iostream>

using namespace std;

// 打印两个有序链表的公共部分

struct Node
{
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

void printCommonPart(Node *head1, Node *head2)
{
    if (head1 == nullptr || head2 == nullptr)
        return;

    Node *p1 = head1, *p2 = head2;
    while (p1 != nullptr && p2 != nullptr)
    {
        if (p1->value < p2->value)
            p1 = p1->next;
        if (p1->value > p2->value)
            p2 = p2->next;

        if (p1 == p2)
        {
            cout << p1->value << " ";
            p1 = p1->next;
        }
    }
}

int main()
{

    Node *head1 = new Node(1);
    Node *head2 = new Node(2);
    Node *p1 = head1;
    Node *p2 = head2;
    p1->next = new Node(3);
    p1 = p1->next;
    p1->next = new Node(5);
    p1 = p1->next;
    p2->next = new Node(4);
    p2 = p2->next;
    p2->next = new Node(7);
    p2 = p2->next;
    p1->next = p2;
    p2->next = new Node(9);
    p2 = p2->next;
    p2->next = new Node(10);
    p2 = p2->next;

    p1 = head1;
    while (p1 != nullptr)
    {
        cout << p1->value << " ";
        p1 = p1->next;
    }
    cout << endl;

    p2 = head2;
    while (p2 != nullptr)
    {
        cout << p2->value << " ";
        p2 = p2->next;
    }
    cout << endl;

    printCommonPart(head1, head2);

    return 0;
}