
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        int cnt = 0;
        int finish = intervals[0][1];

        for (int i = 1; i < n; i++) {

            int start = intervals[i][0];

            // Check if current interval overlaps
            if (start < finish) {
                cnt++;

                // Keep the interval that finishes earlier
                finish = min(finish, intervals[i][1]);
            }
            else {
                // No overlap, keep current interval
                finish = intervals[i][1];
            }
        }

        return cnt;
    }
};
