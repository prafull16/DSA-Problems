class Solution {
public:
    int countPalindromicSubsequence(string s) {

        vector<int> first(26, -1);
        vector<int> last(26, -1);

        // Store first and last occurrence
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';

            if (first[idx] == -1)
                first[idx] = i;

            last[idx] = i;
        }

        int ans = 0;

        // Check every possible outer character
        for (int ch = 0; ch < 26; ch++) {

            if (first[ch] == -1 || first[ch] == last[ch])
                continue;

            unordered_set<char> st;

            for (int i = first[ch] + 1; i < last[ch]; i++)
                st.insert(s[i]);

            ans += st.size();
        }

        return ans;
    }
};