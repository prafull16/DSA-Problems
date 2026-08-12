class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        // power[i] = 2^i % MOD
        vector<long long> power(n);

        power[0] = 1;

        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        int left = 0;
        int right = n - 1;

        long long ans = 0;

        while (left <= right) {

            if (nums[left] + nums[right] <= target) {

                // nums[left] is minimum
                // nums[right] can be the maximum
                // Every element between them has 2 choices.
                ans = (ans + power[right - left]) % MOD;

                left++;
            }
            else {
                right--;
            }
        }

        return ans;
    }
};