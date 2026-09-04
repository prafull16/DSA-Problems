class Solution {
public:

    void combinationSum2(vector<int>& arr, int target, int i,
                         vector<vector<int>>& ans, vector<int>& curr) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (i == arr.size() || target < 0) {
            return;
        }

        // Include
        curr.push_back(arr[i]);

        combinationSum2(arr, target - arr[i], i + 1, ans, curr);

        // Backtrack
        curr.pop_back();

        // Exclude all duplicate values
        int index = i + 1;

        while (index < arr.size() && arr[index] == arr[i]) {
            index++;
        }

        combinationSum2(arr, target, index, ans, curr);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());

        combinationSum2(candidates, target, 0, ans, curr);

        return ans;
    }
};