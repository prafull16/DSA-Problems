class Solution {
public:

    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;

            start++;
            end--;
        }

        return true;
    }

    void solve(string& s, int i,
               vector<vector<string>>& ans,
               vector<string>& curr) {

        if (i == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int j = i; j < s.size(); j++) {

            if (isPalindrome(s, i, j)) {

                curr.push_back(s.substr(i, j - i + 1));

                solve(s, j + 1, ans, curr);

                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> curr;

        solve(s, 0, ans, curr);

        return ans;
    }
};