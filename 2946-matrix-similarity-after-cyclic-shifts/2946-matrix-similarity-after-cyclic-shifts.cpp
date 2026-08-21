class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k = k % n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i % 2 == 0) {
                    // Even row -> shift LEFT by k
                    // Original mat[i][j] should equal
                    // shifted value coming from (j + k)
                    if (mat[i][j] != mat[i][(j + k) % n])
                        return false;
                }
                else {
                    // Odd row -> shift RIGHT by k
                    // Original mat[i][j] should equal
                    // shifted value coming from (j - k)
                    if (mat[i][j] != mat[i][(j - k + n) % n])
                        return false;
                }
            }
        }

        return true;
    }
};