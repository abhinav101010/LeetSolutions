class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxSize = 0
        for start in range(len(s)):
            st = set()
            for i in range(start, len(s)):
                if s[i] in st:
                    break
                st.add(s[i])
            maxSize = max(maxSize, len(st))
        return maxSize