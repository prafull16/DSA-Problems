class Solution {
public:
    bool canJump(vector<int>& nums) {

        int i = 0;
        int n = nums.size();
        int maxReach = 0;

        while (i < n) {

            // If current index is beyond the farthest reachable index,
            // it means we cannot reach this position.
            if (i > maxReach) {
                return false;
            }

            // Update the farthest index we can reach.
            maxReach = max(maxReach, i + nums[i]);

            i++;
        }

        return true;
    }
};