class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) {
            return "";
        }
        
        unordered_map<char, int> target;
        for (char c : t) {
            target[c]++;
        }
        int required = target.size();
        
        int left = 0;
        int formed = 0;
        unordered_map<char, int> windowCounts;
        
        int ansLen = INT_MAX, ansLeft = -1, ansRight = -1;
        
        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];
            windowCounts[c]++;
            
            if (target.count(c) && windowCounts[c] == target[c]) {
                formed++;
            }
            
            while (left <= right && formed == required) {
                c = s[left];
                
                if (right - left + 1 < ansLen) {
                    ansLen = right - left + 1;
                    ansLeft = left;
                    ansRight = right;
                }
                
                windowCounts[c]--;
                if (target.count(c) && windowCounts[c] < target[c]) {
                    formed--;
                }
                
                left++;
            }
        }
        
        return ansLen == INT_MAX ? "" : s.substr(ansLeft, ansLen);
    }
};