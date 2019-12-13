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

class WordDictionary
{
private:
    TrieNode *root;

    bool dfs(TrieNode *node, string &word, int index)
    {
        // word[index] == '.'
        for (int i = 0; i < 26; ++i)
        {
            TrieNode *cur = node->next[i];
            if (cur == nullptr)
                continue;

            bool curPath = true;
            for (int j = index + 1; j < word.size(); ++j)
            {
                if (word.at(j) == '.')
                {
                    curPath = dfs(cur, word, j);
                    if (curPath)
                        return true;
                    break;
                }

                int idx = word.at(j) - 'a';
                if (cur->next[idx] == nullptr)
                {
                    curPath = false;
                    break;
                }

                cur = cur->next[idx];
            }
            if (curPath && cur->end > 0)
                return true;
        }

        return false;
    }

public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    ~WordDictionary()
    {
        delete (root);
    }

    /*
     * @param word: Adds a word into the data structure.
     * @return: nothing
     */
    void addWord(string &word)
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
     * @param word: A word could contain the dot character '.' to represent any one letter.
     * @return: if the word is in the data structure.
     */
    bool search(string &word)
    {
        if (word.size() == 0)
            return false;

        TrieNode *cur = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (word.at(i) == '.')
                return dfs(cur, word, i);

            int index = word.at(i) - 'a';
            if (cur->next[index] == nullptr)
                return false;

            cur = cur->next[index];
        }

        return cur->end > 0;
    }

};
