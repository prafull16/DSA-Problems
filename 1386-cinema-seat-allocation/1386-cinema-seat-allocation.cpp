class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        // Store reserved seats for each row
        unordered_map<int, unordered_set<int>> reserved;

        for (auto &seat : reservedSeats) {
            reserved[seat[0]].insert(seat[1]);
        }

        // Initially, every row can accommodate 2 groups
        int ans = 2 * n;

        // Only rows having reserved seats need to be checked
        for (auto &[row, seats] : reserved) {

            bool left = true;   // 2,3,4,5
            bool middle = true; // 4,5,6,7
            bool right = true;  // 6,7,8,9

            // Check left block
            for (int s = 2; s <= 5; s++) {
                if (seats.count(s)) {
                    left = false;
                    break;
                }
            }

            // Check middle block
            for (int s = 4; s <= 7; s++) {
                if (seats.count(s)) {
                    middle = false;
                    break;
                }
            }

            // Check right block
            for (int s = 6; s <= 9; s++) {
                if (seats.count(s)) {
                    right = false;
                    break;
                }
            }

            // This row was initially counted as 2.
            // Now calculate its actual number of groups.
            if (left && right) {
                // Two groups can sit:
                // 2,3,4,5 and 6,7,8,9
                continue;
            }
            else if (left || middle || right) {
                // Only one group can sit
                ans--;
            }
            else {
                // No group can sit
                ans -= 2;
            }
        }

        return ans;
    }
};