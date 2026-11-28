
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();

        // Step 1: Add intervals before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // Step 2: Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {

            if (intervals[i][0] < newInterval[0]) {
                newInterval[0] = intervals[i][0];
            }

            if (intervals[i][1] > newInterval[1]) {
                newInterval[1] = intervals[i][1];
            }

            i++;
        }

        // Add the merged newInterval
        ans.push_back(newInterval);

        // Step 3: Add remaining intervals
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};
