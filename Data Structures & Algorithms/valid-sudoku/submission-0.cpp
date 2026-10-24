#include <unordered_map>

class Solution
{
    public:
        bool isValidSudoku(vector<vector<char>>& board)
        {
            vector<unordered_map<char, uint8_t>> row_counts(board.size());
            vector<unordered_map<char, uint8_t>> column_counts(board.size());
            vector<unordered_map<char, uint8_t>> square_counts(board.size());
            uint8_t square_index = 0;

            for (uint8_t i = 0; i < board.size(); ++i)
            {
                for (uint8_t j = 0; j < board.size(); ++j)
                {
                    if (board[i][j] == '.') continue;

                    row_counts[i][board[i][j]]++;
                    if (row_counts[i][board[i][j]] == 2) return false;


                    column_counts[j][board[i][j]]++;
                    if (column_counts[j][board[i][j]] == 2) return false;

                    square_index = (i / 3) * 3 + j / 3;
                    square_counts[square_index][board[i][j]]++;
                    if (square_counts[square_index][board[i][j]] == 2) return false;
                }
            }

            return true;
        }
};
