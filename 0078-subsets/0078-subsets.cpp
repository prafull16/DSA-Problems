class Solution {
public:

    void solve(vector<int>& nums, vector<int>& curr,
               int i, vector<vector<int>>& ans) {

        // Base case:
        // We have considered every element.
        if (i == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // INCLUDE nums[i]
        curr.push_back(nums[i]);

        solve(nums, curr, i + 1, ans);

        // BACKTRACK
        // Remove nums[i] before trying the exclude case.
        curr.pop_back();

        // EXCLUDE nums[i]
        solve(nums, curr, i + 1, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> curr;

        solve(nums, curr, 0, ans);

        return ans;
    }
};