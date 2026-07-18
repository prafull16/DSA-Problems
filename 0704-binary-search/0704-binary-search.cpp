class Solution {
public:
    int binary(vector<int>& nums, int target, int s, int e) {
        if (s > e) {
            return -1;
        }
        
        int mid = s + (e - s) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > target) {
            return binary(nums, target, s, mid - 1);
        }
        else {
            return binary(nums, target, mid + 1, e);
        }
    }
    
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        return binary(nums, target, 0, nums.size() - 1);
    }
};