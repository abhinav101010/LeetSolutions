class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> count;
        int left = 0, res = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            count[s[right]]++;
            while ((int)count.size() > k) {
                count[s[left]]--;
                if (count[s[left]] == 0) {
                    count.erase(s[left]);
                }
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};