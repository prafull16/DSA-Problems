
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        if (n == 0) return 0;

        // Sort according to ending time
        sort(intervals.begin(), intervals.end(),
             [](auto a, auto b) {
                 return a[1] < b[1];
             });

        int cnt = 1;
        int lastEnd = intervals[0][1];

        // Check remaining intervals
        for (int i = 1; i < n; i++) {

            if (intervals[i][0] >= lastEnd) {

                cnt++;
                lastEnd = intervals[i][1];
            }
        }

        // Minimum intervals to remove
        return n - cnt;
    }
};
