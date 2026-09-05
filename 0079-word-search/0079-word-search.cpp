class Solution {
public:

    bool solve(vector<vector<char>>& board, string& word,
               int i, int j, int h) {

        // Whole word found
        if (h == word.size()) {
            return true;
        }

        // Boundary check
        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size()) {
            return false;
        }

        // Current cell doesn't match
        if (board[i][j] != word[h]) {
            return false;
        }

        // Mark current cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Check all 4 directions
        bool found =
            solve(board, word, i - 1, j, h + 1) ||  // up
            solve(board, word, i + 1, j, h + 1) ||  // down
            solve(board, word, i, j - 1, h + 1) ||  // left
            solve(board, word, i, j + 1, h + 1);     // right

        // Undo / backtrack
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (solve(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};