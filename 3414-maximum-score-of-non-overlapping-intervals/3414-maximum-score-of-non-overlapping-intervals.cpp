class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // {l, r, w, originalIndex}, sorted by r ascending
        vector<array<long long,4>> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};

        sort(arr.begin(), arr.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });

        vector<long long> rs(n);
        for (int i = 0; i < n; i++) rs[i] = arr[i][1];

        // dp[i][k] = {bestScore, bestIndices (sorted ascending)} 
        // using first i intervals (sorted by r), choosing at most k
        vector<vector<long long>> score(n + 1, vector<long long>(5, 0));
        vector<vector<vector<int>>> pick(n + 1, vector<vector<int>>(5));

        for (int i = 1; i <= n; i++) {
            long long l = arr[i - 1][0];
            long long w = arr[i - 1][2];
            int origIdx = (int)arr[i - 1][3];

            // count of intervals among first i-1 with r < l (strict, boundary overlap not allowed)
            int j = lower_bound(rs.begin(), rs.begin() + (i - 1), l) - rs.begin();

            for (int k = 0; k <= 4; k++) {
                long long bestScore = score[i - 1][k];
                vector<int> bestIdx = pick[i - 1][k];

                if (k >= 1) {
                    long long takeScore = score[j][k - 1] + w;
                    vector<int> takeIdx = pick[j][k - 1];
                    auto pos = upper_bound(takeIdx.begin(), takeIdx.end(), origIdx);
                    takeIdx.insert(pos, origIdx);

                    if (takeScore > bestScore ||
                        (takeScore == bestScore && takeIdx < bestIdx)) {
                        bestScore = takeScore;
                        bestIdx = takeIdx;
                    }
                }
                score[i][k] = bestScore;
                pick[i][k] = bestIdx;
            }
        }

        return pick[n][4];
    }
};