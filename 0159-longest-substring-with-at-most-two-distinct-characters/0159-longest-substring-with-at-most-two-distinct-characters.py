class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        from collections import defaultdict
        count = defaultdict(int)
        left = 0
        res = 0
        for right in range(len(s)):
            count[s[right]] += 1
            while len(count) > 2:
                count[s[left]] -= 1
                if count[s[left]] == 0:
                    del count[s[left]]
                left += 1
            res = max(res, right - left + 1)
        return res