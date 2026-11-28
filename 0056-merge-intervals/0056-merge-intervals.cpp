
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (int i = 0; i < intervals.size(); i++) {

            // If answer is empty OR intervals don't overlap
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            }

            // If intervals overlap
            else {
                if (intervals[i][1] > ans.back()[1]) {
                    ans.back()[1] = intervals[i][1];
                }
            }
        }

        return ans;
    }
};
