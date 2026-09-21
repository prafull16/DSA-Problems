class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);
        vector<long long> newDp(k, 0);

        for (int num : nums) {
            fill(newDp.begin(), newDp.end(), 0);
            int numMod = num % k;

            // Start a new subarray consisting of just this element
            newDp[numMod] += 1;

            // Extend all subarrays ending at the previous index
            for (int r = 0; r < k; r++) {
                if (dp[r] == 0) continue; // skip empty buckets for speed
                int newMod = (int)(((long long)r * numMod) % k);
                newDp[newMod] += dp[r];
            }

            dp.swap(newDp);

            // Accumulate into final result
            for (int r = 0; r < k; r++) {
                result[r] += dp[r];
            }
        }

        return result;
    }
};