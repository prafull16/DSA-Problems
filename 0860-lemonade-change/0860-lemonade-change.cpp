class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
          int f = 0;  // Number of $5 bills
        int t = 0;  // Number of $10 bills

        for(int i = 0; i < bills.size(); i++) {

            if(bills[i] == 5) {
                f++;
            }

            else if(bills[i] == 10) {

                if(f > 0) {
                    f--;
                    t++;
                }
                else {
                    return false;
                }
            }

            else if(bills[i] == 20) {

                // Prefer $10 + $5
                if(t > 0 && f > 0) {
                    t--;
                    f--;
                }

                // Otherwise use three $5 bills
                else if(f >= 3) {
                    f -= 3;
                }

                else {
                    return false;
                }
            }
        }

        return true;
    }
};