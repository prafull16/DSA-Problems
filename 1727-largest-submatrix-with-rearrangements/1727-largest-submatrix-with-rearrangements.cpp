class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Step 1: Calculate consecutive 1s vertically
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (matrix[i][j] == 1) {
                    matrix[i][j] = matrix[i - 1][j] + 1;
                }
            }
        }

        int ans = 0;

        // Step 2: For every row
        for (int i = 0; i < m; i++) {

            // Sort heights in descending order
            sort(matrix[i].rbegin(), matrix[i].rend());

            // Step 3: Calculate maximum area
            for (int j = 0; j < n; j++) {

                int height = matrix[i][j];
                int width = j + 1;

                ans = max(ans, height * width);
            }
        }

        return ans;
    }
};