class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;
        
        for (int i = 0; i < n; i++) {
            // If current index is beyond max reachable position
            if (i > maxReach) {
                return false;
            }
            
            // Update maximum reachable position
            maxReach = max(maxReach, i + nums[i]);
            
            // If we can already reach the last index
            if (maxReach >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};