class Solution {
public:
    bool lemonadeChange(vector<int>& arr) {

        int five = 0 ; 
        int ten = 0 ;

        if(arr[0] != 5)  return false;

        for(int i = 0 ; i < arr.size() ; i++){

            if(arr[i] == 5) five++;
            
                        if(arr[i] == 10){ 

                            if(five > 0 ){
                            ten++;
                            five--; }
                        else{
                            return false;
                        }
                        
                        }

                            if(arr[i] == 20){
                                if(five > 0 && ten > 0 ){
                                    ten--;
                                    five--;
                                } 
                                else if( five >= 3){
                                    five -= 3;
                                }
                                else{
                                    return false;
                                }
                            }     
                    
        }
        
        return true;
    }
};