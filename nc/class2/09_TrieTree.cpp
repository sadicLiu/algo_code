#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TrieNode
{
    int freq;
    int end;
    TrieNode *next[26];

    TrieNode()
    {
        freq = 0;
        end = 0;
        for (int i = 0; i < 26; ++i)
        {
            next[i] = nullptr;
        }
    }
};

class TrieTree
{
private:
    TrieNode *root;

public:
    TrieTree()
    {
        root = new TrieNode();
    }

    ~TrieTree()
    {
        delete root;
    }

    // 将给定字符串插入前缀树
    void insert(string word)
    {
        if (word.size() == 0)
            return;

        TrieNode *cur = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int index = word.at(i) - 'a';
            if (cur->next[index] == nullptr)
                cur->next[index] = new TrieNode();
            cur->next[index]->freq++;

            cur = cur->next[index];
        }

        cur->end++;
    }

    // 给定字符串出现的次数
    int search(string word)
    {
        if (word.size() == 0)
            return 0;

        TrieNode *cur = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int index = word.at(i) - 'a';
            if (cur->next[index] == nullptr)
                return 0;

            cur = cur->next[index];
        }

        return cur->end;
    }

    // 这个操作是可选的, 具体根据题意是否需要删除操作来决定是否实现这个函数
    void del(string word)
    {
        int count = search(word);
        if (count == 0)
            return;

        TrieNode *cur = root;
        vector<TrieNode *> nodes;
        for (int i = 0; i < word.size(); ++i)
        {
            int index = word.at(i) - 'a';
            cur->next[index]->freq--;

            if (cur->next[index]->freq == 0)
                nodes.push_back(cur->next[index]);

            if (nodes.size() == 1)
            {
                TrieNode *pre = cur;
                cur = cur->next[index];
                pre->next[index] = nullptr;
            } else
                cur = cur->next[index];
        }

        while (!nodes.empty())
        {
            cur = nodes.back();
            nodes.pop_back();
            delete cur;
        }
    }
};