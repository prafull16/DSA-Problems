class Solution {
public:
    double myPow(double x, int n) {

        long long N = n;      // convert to long long

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return power(x, N);
    }

    double power(double x, long long n) {

        if (n == 0)
            return 1;

        double half = power(x, n / 2);

        if (n % 2 == 0)
            return half * half;

        return x * half * half;
    }
};