class Solution {
public:
    using ll = long long;

    ll LIMIT;
    vector<ll> fact;

    ll comb(int n, int r) {
        if (r > n) return 0;
        __int128 res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res > LIMIT) return LIMIT;
        }
        return min((ll)res, LIMIT);
    }

    ll countWays(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt) total += x;

        __int128 ans = 1;
        int rem = total;

        for (int x : cnt) {
            if (x == 0) continue;
            ans *= comb(rem, x);
            if (ans > LIMIT) return LIMIT;
            rem -= x;
        }

        return min((ll)ans, LIMIT);
    }

    string smallestPalindrome(string s, long long k) {
        LIMIT = k;

        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> half(26);
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] % 2)
                mid = char('a' + i);
        }

        int m = 0;
        for (int x : half) m += x;

        if (countWays(half) < k) return "";

        string left;

        for (int pos = 0; pos < m; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;

                ll ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid)
            return left + string(1, mid) + right;
        return left + right;
    }
};