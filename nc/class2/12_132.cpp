#include <iostream>
#include <vector>
#include <map>
#include <set>

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

class Solution
{

private:
    TrieNode *root;

public:
    Solution()
    {
        root = new TrieNode();
    }

    ~Solution()
    {
        delete root;
    }

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

    int search(string &word)
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

    vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> res;
        if (board.size() == 0 || board[0].size() == 0 || words.size() == 0)
            return res;

        for (int i = 0; i < words.size(); ++i)
        {
            insert(words[i]);
        }

        set<string> resSet;
        int rows = board.size();
        int cols = board[0].size();
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                int index = board[r][c] - 'a';
                if (root->next[index] == nullptr)
                    continue;

                string curWord = {board[r][c]};
                bool *visit = new bool[rows * cols]();
                visit[r * cols + c] = true;

                dfs(board, r, c, root->next[index], curWord, visit, resSet);

                delete[] visit;
            }
        }

        res.assign(resSet.begin(), resSet.end());

        return res;
    }

    void
    dfs(vector<vector<char>> &board, int r, int c, TrieNode *node, string &curWord, bool *visit, set<string> &res)
    {
        if (node->end > 0)
        {
            res.insert(curWord);
        }

        int rows = board.size();
        int cols = board[0].size();

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        for (int i = 0; i < 4; ++i)
        {
            int nextR = r + dx[i];
            int nextC = c + dy[i];
            if (nextR >= 0 && nextR < rows && nextC >= 0 && nextC < cols)
            {
                int index = board[nextR][nextC] - 'a';
                if (visit[nextR * cols + nextC] || node->next[index] == nullptr)
                    continue;

                visit[nextR * cols + nextC] = true;
                curWord += board[nextR][nextC];
                dfs(board, nextR, nextC, node->next[index], curWord, visit, res);

                visit[nextR * cols + nextC] = false;
                curWord = curWord.substr(0, curWord.size() - 1);
            }
        }
    }
};

/*
int main()
{
    Solution solution;
    vector<vector<char>> board = {{'a', 'c'},
                                  {'c', 'b'}};
    vector<string> words = {"ab"};
    solution.wordSearchII(board, words);

    return 0;
}*/
