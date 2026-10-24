#include <unordered_map>

class Solution
{
    public:

        const uint8_t board_size = 9;

        bool isValidSudoku(vector<vector<char>>& board)
        {
            vector<unordered_map<char, uint8_t>> row_counts(board_size);
            vector<unordered_map<char, uint8_t>> column_counts(board_size);
            vector<unordered_map<char, uint8_t>> square_counts(board_size);

            for (uint8_t i = 0; i < board_size; ++i)
            {
                for (uint8_t j = 0; j < board_size; ++j)
                {
                    if (board[i][j] == '.') continue;

                    row_counts[i][board[i][j]]++;
                    if (row_counts[i][board[i][j]] == 2) return false;


                    column_counts[j][board[i][j]]++;
                    if (column_counts[j][board[i][j]] == 2) return false;

                    square_counts[(i / 3) * 3 + j / 3][board[i][j]]++;
                    if (square_counts[(i / 3) * 3 + j / 3][board[i][j]] == 2) return false;
                }
            }

            return true;
        }
};
