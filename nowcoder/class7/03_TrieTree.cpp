#include <iostream>
#include <vector>

using namespace std;

class TrieNode
{
public:
    int freq;  // 当前节点被访问次数
    int end;  // 以当前节点结尾的字符串数
    TrieNode *nexts[26];  // 当前节点之后的所有路径，共26个字母

    TrieNode()
    {
        freq = 0;
        end = 0;
        for (int i = 0; i < 26; ++i)
            nexts[i] = nullptr;
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
        if (nullptr != root)
            delete root;
    }

    void insert(string word)
    {
        if (word.length() == 0)
            return;

        char *ch = const_cast<char *>(word.data());
        int index;
        TrieNode *cur = root;
        for (int i = 0; i < word.length(); ++i)
        {
            index = ch[i] - 'a';
            if (cur->nexts[index] == nullptr)
                cur->nexts[index] = new TrieNode();
            cur = cur->nexts[index];
            cur->freq++;
        }
        cur->end++;
    }

    // 给定字符串出现次数
    int search(string word)
    {
        if (word.length() == 0)
            return 0;

        char *ch = (char *) word.data();
        int index;
        TrieNode *cur = root;
        for (int i = 0; i < word.length(); ++i)
        {
            index = ch[i] - 'a';
            if (cur->nexts[index] == nullptr)
                return 0;
            cur = cur->nexts[index];
        }
        return cur->end;
    }

    void del(string word)
    {
        if (word.length() == 0 || !search(word))
            return;

        vector<TrieNode *> toBeDel;
        char *p = (char *) word.data();
        TrieNode *cur = root;
        TrieNode *pre;
        for (int i = 0; i < word.length(); ++i)
        {
            int index = p[i] - 'a';
            cur->nexts[index]->freq--;
            if (cur->nexts[index]->freq == 0)
                toBeDel.push_back(cur->nexts[index]);

            if (toBeDel.size() == 1)
            {
                pre = cur;
                cur = cur->nexts[index];
                pre->nexts[index] = nullptr;
            } else
            {
                cur = cur->nexts[index];
            }
        }

        for (int j = 0; j < toBeDel.size(); ++j)
        {
            delete toBeDel[j];
        }
    }
};

int main()
{
    TrieTree tree;
    tree.insert("abc");
    tree.insert("abc");
    tree.insert("abcd");
    cout << tree.search("abcd") << endl;  // 1

    tree.del("abcd");
    cout << tree.search("abcd") << endl;  // 0

    cout << tree.search("abc") << endl;  // 2

    return 0;
}