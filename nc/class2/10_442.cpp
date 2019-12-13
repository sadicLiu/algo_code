#include <iostream>

using namespace std;

struct TrieNode
{
    int end;
    TrieNode *next[26];

    TrieNode()
    {
        end = 0;
        for (int i = 0; i < 26; ++i)
        {
            next[i] = nullptr;
        }
    }
};

class Trie
{
private:
    TrieNode *root;
public:
    Trie()
    {
        root = new TrieNode();
    }

    ~Trie()
    {
        delete root;
    }

    /*
     * @param word: a word
     * @return: nothing
     */
    void insert(string &word)
    {
        if (word.size() == 0)
            return;

        TrieNode *cur = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int index = word.at(i) - 'a';
            if (cur->next[index] == nullptr)
                cur->next[index] = new TrieNode();
            cur = cur->next[index];
        }

        cur->end++;
    }

    /*
     * @param word: A string
     * @return: if the word is in the trie.
     */
    bool search(string &word)
    {
        if (word.size() == 0)
            return false;

        TrieNode *cur = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int index = word.at(i) - 'a';
            if (cur->next[index] == nullptr)
                return false;
            cur = cur->next[index];
        }

        return cur->end > 0;
    }

    /*
     * @param prefix: A string
     * @return: if there is any word in the trie that starts with the given prefix.
     */
    bool startsWith(string &prefix)
    {
        if (prefix.size() == 0)
            return false;

        TrieNode *cur = root;
        for (int i = 0; i < prefix.size(); ++i)
        {
            int index = prefix.at(i) - 'a';
            if (cur->next[index] == nullptr)
                return false;
            cur = cur->next[index];
        }

        return true;
    }
};