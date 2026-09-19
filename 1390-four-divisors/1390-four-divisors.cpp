    class Solution {
    public:
        int sumFourDivisors(vector<int>& nums) {

            vector<int> ans;
        

            for(int i = 0 ; i < nums.size() ; i++){

                int sum = 0;
                int cnt = 0;

                for(int j = 1 ; j <= nums[i] ; j++  ){

                    if(nums[i] % j == 0){
                        sum += j;
                        cnt++;
                    }

                    
                    if(cnt > 4) {
                        break;
                    }

                   
                }
                 if(cnt == 4)  ans.push_back(sum);
            }

            if(ans.size() == 0) return 0;

            int x = 0;

            for(int i = 0 ; i < ans.size() ; i++){
              
              x += ans[i];

            }
            
            return x;
        }
    };