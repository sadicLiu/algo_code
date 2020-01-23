#include <iostream>

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
        root = new TrieNode;
    }

    ~TrieTree()
    {
        delete root;
    }

    void insert(string word)
    {
        if (word.size() == 0)
            return;

        TrieNode *cur = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int index = word.at(i) - 'a';
            if (cur->next[index] == nullptr)
            {
                cur->next[index] = new TrieNode();
            }
            cur->next[index]->freq++;
            cur = cur->next[index];
        }
        cur->end++;
    }

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
};
