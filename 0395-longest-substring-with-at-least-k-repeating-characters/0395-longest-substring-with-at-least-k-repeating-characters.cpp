class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() < k) return 0;
        
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0 && count[i] < k) {
                char splitChar = 'a' + i;
                int maxLen = 0;
                size_t start = 0;
                while (start < s.size()) {
                    size_t end = s.find(splitChar, start);
                    if (end == string::npos) end = s.size();
                    if (end > start) {
                        maxLen = max(maxLen, longestSubstring(s.substr(start, end - start), k));
                    }
                    start = end + 1;
                }
                return maxLen;
            }
        }
        
        return s.size();
    }
};