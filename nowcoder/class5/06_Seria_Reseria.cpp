#include "BinaryTreeUtils.h"
#include <iostream>
#include <queue>

using namespace std;

// 二叉树的序列化和反序列

string serial(Node *root)
{
    if (root == nullptr)
        return "#_";

    string result = to_string(root->value) + "_";
    result += serial(root->left);
    result += serial(root->right);

    return result;
}

Node *deserialCore(queue<char> &elem)
{
    if (elem.size() == 0)
        return nullptr;

    char cur_elem = elem.front();
    elem.pop();

    Node *root = (cur_elem == '#') ? nullptr : new Node(cur_elem - '0');
    if (root != nullptr)
    {
        root->left = deserialCore(elem);
        root->right = deserialCore(elem);
    }

    return root;
}

Node *deserial(string result)
{
    queue<char> que;
    for (int i = 0; i < result.size(); i++)
    {
        char cur = result[i];
        if (cur != '_')
            que.push(cur);
    }

    return deserialCore(que);
}


int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->right->left = new Node(5);
//    printTree(root);

    string result = serial(root);
    cout << result << endl;

    Node *newRoot = deserial(result);
    printTree(newRoot);


    return 0;
}