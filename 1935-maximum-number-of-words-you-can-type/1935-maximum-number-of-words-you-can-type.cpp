class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int count = 0;
        bool canType = true;
        
        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') {
                if (canType) count++;
                canType = true; // Reset for next word
            } else if (broken.count(text[i])) {
                canType = false; // Mark this word as untypable
            }
        }
        
        return count;
    }
};