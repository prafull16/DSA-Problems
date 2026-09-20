class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        
        vector<char> isComposite(n, 0);
        int count = 1; // account for prime number 2
        
        for (int i = 3; i < n; i += 2) {
            if (!isComposite[i]) {
                count++;
                if ((long long)i * i < n) {
                    for (long long j = (long long)i * i; j < n; j += 2 * i) {
                        isComposite[j] = 1;
                    }
                }
            }
        }
        
        return count;
    }
};