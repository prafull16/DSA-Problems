class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // prefix[i][j] = X count - Y count
        vector<vector<int>> prefix(m, vector<int>(n, 0));

        // xCount[i][j] = number of X's
        // in rectangle (0,0) to (i,j)
        vector<vector<int>> xCount(m, vector<int>(n, 0));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int value = 0;
                int x = 0;

                if (grid[i][j] == 'X') {
                    value = 1;
                    x = 1;
                }
                else if (grid[i][j] == 'Y') {
                    value = -1;
                }

                // 2D prefix sum
                prefix[i][j] = value;
                xCount[i][j] = x;

                if (i > 0) {
                    prefix[i][j] += prefix[i - 1][j];
                    xCount[i][j] += xCount[i - 1][j];
                }

                if (j > 0) {
                    prefix[i][j] += prefix[i][j - 1];
                    xCount[i][j] += xCount[i][j - 1];
                }

                // Added the top-left corner twice
                if (i > 0 && j > 0) {
                    prefix[i][j] -= prefix[i - 1][j - 1];
                    xCount[i][j] -= xCount[i - 1][j - 1];
                }

                // Equal X and Y + at least one X
                if (prefix[i][j] == 0 && xCount[i][j] > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};