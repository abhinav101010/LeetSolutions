class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;
        int n = words.size();
        
        while (i < n) {
            int lineLen = words[i].size();
            int j = i + 1;
            while (j < n && lineLen + 1 + (int)words[j].size() <= maxWidth) {
                lineLen += 1 + words[j].size();
                j++;
            }
            
            int numWords = j - i;
            bool isLastLine = (j == n);
            
            if (isLastLine || numWords == 1) {
                // Last line or single word: left-justified
                string line = words[i];
                for (int k = i + 1; k < j; k++) {
                    line += ' ' + words[k];
                }
                line += string(maxWidth - line.size(), ' ');
                result.push_back(line);
            } else {
                // Fully justified
                int totalSpaces = maxWidth;
                for (int k = i; k < j; k++) {
                    totalSpaces -= words[k].size();
                }
                int spacesBetween = numWords - 1;
                int spacePerGap = totalSpaces / spacesBetween;
                int extraSpaces = totalSpaces % spacesBetween;
                
                string line = words[i];
                for (int k = 1; k < numWords; k++) {
                    int spaces = spacePerGap + (k <= extraSpaces ? 1 : 0);
                    line += string(spaces, ' ') + words[i + k];
                }
                result.push_back(line);
            }
            
            i = j;
        }
        
        return result;
    }
};