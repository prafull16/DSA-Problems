#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLen = words[i].size();
            int j = i + 1;

            while (j < n && lineLen + 1 + words[j].size() <= maxWidth) {
                lineLen += 1 + words[j].size();
                j++;
            }

            int wordCount = j - i;
            string line;

            if (j == n || wordCount == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += ' ';
                }

                while (line.size() < maxWidth) {
                    line += ' ';
                }
            } 
            else {
                int totalChars = 0;
                for (int k = i; k < j; k++) {
                    totalChars += words[k].size();
                }

                int totalSpaces = maxWidth - totalChars;
                int gaps = wordCount - 1;

                int spacesEach = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        int spaces = spacesEach;

                        if (extraSpaces > 0) {
                            spaces++;
                            extraSpaces--;
                        }

                        line += string(spaces, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};