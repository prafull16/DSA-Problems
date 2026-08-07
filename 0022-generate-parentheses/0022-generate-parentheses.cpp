class Solution {
public:

    void solve(int n, int open, int close,
               string &s, vector<string> &ans) {

        // If we used all n opening and n closing brackets
        // then s is a complete valid answer.
        if (open == n && close == n) {
            ans.push_back(s);
            return;
        }

        // Add '(' if we still have opening brackets available
        if (open < n) {
            s.push_back('(');

            solve(n, open + 1, close, s, ans);

            // Backtrack: remove the '('
            s.pop_back();
        }

        // Add ')' only if there is an unmatched '('
        if (close < open) {
            s.push_back(')');

            solve(n, open, close + 1, s, ans);

            // Backtrack: remove the ')'
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string s = "";

        solve(n, 0, 0, s, ans);

        return ans;
    }
};