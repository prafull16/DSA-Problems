class Solution {
public:

    long long MOD = 1000000007;

    // Binary Exponentiation
    long long even(long long x, long long n) {

        // Base case
        if (n == 0)
            return 1;

        // Even exponent
        if (n % 2 == 0) {

            // (x*x) can become very large,
            // so take modulo after multiplication.
            return even((x * x) % MOD, n / 2);
        }

        // Odd exponent
        // Multiply by x once because exponent is odd.
        return (x * even((x * x) % MOD, n / 2)) % MOD;
    }

    int countGoodNumbers(long long n) {

        // Number of odd indices
        long long odd = n / 2;

        // Number of even indices
        long long evenPos = n - odd;

        // 5^(number of even positions)
        long long first = even(5, evenPos);

        // 4^(number of odd positions)
        long long second = even(4, odd);

        // Multiply both answers
        return (first * second) % MOD;
    }
};
