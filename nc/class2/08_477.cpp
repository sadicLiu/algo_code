#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    /*
     * @param board: board a 2D board containing 'X' and 'O'
     * @return: nothing
     */
    void surroundedRegions(vector<vector<char>> &board)
    {
        if (board.size() == 0 || board[0].size() == 0)
            return;

        int rows = board.size();
        int cols = board[0].size();
        if (rows * cols == 1)
            return;

        for (int i = 0; i < cols - 1; ++i)
        {
            if (board[0][i] == 'O')
                infect(board, 0, i);
        }
        for (int j = 0; j < rows - 1; ++j)
        {
            if (board[j][cols - 1] == 'O')
                infect(board, j, cols - 1);
        }
        for (int k = cols - 1; k > 0; --k)
        {
            if (board[rows - 1][k] == 'O')
                infect(board, rows - 1, k);
        }
        for (int l = rows - 1; l > 0; --l)
        {
            if (board[l][0] == 'O')
                infect(board, l, 0);
        }

        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (board[r][c] == 'Z')
                    board[r][c] = 'O';
                else if (board[r][c] == 'O')
                    board[r][c] = 'X';
            }
        }
    }

    void infect(vector<vector<char>> &board, int r, int c)
    {
        int rows = board.size();
        int cols = board[0].size();

        board[r][c] = 'Z';
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        for (int i = 0; i < 4; ++i)
        {
            int nextR = r + dx[i];
            int nextC = c + dy[i];
            if (nextR >= 0 && nextR < rows && nextC >= 0 && nextC < cols && board[nextR][nextC] == 'O')
            {
                infect(board, nextR, nextC);
            }
        }

    }
};