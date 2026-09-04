class Solution {
public:

    void solve(vector<int>& arr , int i , vector<vector<int>>&ans , vector<int> curr){

        if(i == arr.size()){
            ans.push_back(curr);
            return;
        }

        int index = i + 1;

        curr.push_back(arr[i]);

        solve(arr , i+1 , ans , curr);

        curr.pop_back();

        while(index < arr.size() && arr[index] == arr[i]){
            index++;
        }
   
        solve(arr , index , ans , curr);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> curr;
        vector<vector<int>> ans;

        sort(nums.begin() , nums.end());
        solve( nums , 0 , ans , curr);

        return ans;
    }
};