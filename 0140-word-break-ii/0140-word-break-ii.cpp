class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Convert dictionary to unordered_set for O(1) lookup
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        // Memoization map: index -> possible sentences from that index
        unordered_map<int, vector<string>> memo;
        
        return dfs(s, dict, 0, memo);
    }
    
private:
    vector<string> dfs(const string& s, const unordered_set<string>& dict, 
                       int start, unordered_map<int, vector<string>>& memo) {
        // If we've already computed sentences starting from this index
        if (memo.find(start) != memo.end()) {
            return memo[start];
        }
        
        vector<string> result;
        
        // If we've reached the end, return empty string to indicate a valid segmentation
        if (start == s.length()) {
            result.push_back("");
            return result;
        }
        
        // Try all possible substrings starting from 'start'
        for (int end = start + 1; end <= s.length(); end++) {
            string word = s.substr(start, end - start);
            
            // If this substring is a valid word in the dictionary
            if (dict.find(word) != dict.end()) {
                // Get all possible sentences from the remaining string
                vector<string> subSentences = dfs(s, dict, end, memo);
                
                // Build complete sentences
                for (const string& sub : subSentences) {
                    if (sub.empty()) {
                        result.push_back(word);
                    } else {
                        result.push_back(word + " " + sub);
                    }
                }
            }
        }
        
        // Store result in memo before returning
        memo[start] = result;
        return result;
    }
};