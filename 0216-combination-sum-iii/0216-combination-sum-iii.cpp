class Solution {    
public:
        void solve( vector<vector<int>> &ans , int k , int n , int i , vector<int> curr , const vector<int>& nums){

                if( k == 0 ){
                    if( n == 0){
                        ans.push_back(curr);
                    }
                    return;
                }

                if(i == nums.size()){
                    return;
                }
    
        //include
        curr.push_back(nums[i]);
        solve(ans , k-1 , n - nums[i] , i+1 , curr , nums);

        curr.pop_back();
        // no k -1 because you dont need to decrease k because its exclude choice na gadheeeeeeee
        solve(ans , k , n , i+1 , curr , nums );

        }

        vector<vector<int>> combinationSum3(int k, int n  ) {
            
          vector<vector<int>> ans;
        vector<int> curr;
        vector<int> nums;
        for(int i = 1; i <= 9; i++) nums.push_back(i);
         solve(ans , k , n  , 0 , curr , nums);

         return ans;

        }
    };