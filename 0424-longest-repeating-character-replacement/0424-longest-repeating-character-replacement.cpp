class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxCount = 0;
        int left = 0;
        int result = 0;
        
        for (int right = 0; right < (int)s.size(); right++) {
            count[s[right] - 'a']++;
            maxCount = max(maxCount, count[s[right] - 'a']);
            
            while (right - left + 1 - maxCount > k) {
                count[s[left] - 'a']--;
                left++;
            }
            
            result = max(result, right - left + 1);
        }
        
        return result;
    }
};