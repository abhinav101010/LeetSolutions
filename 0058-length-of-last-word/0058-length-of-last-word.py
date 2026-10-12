class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()[::-1]
        if s.find(" ") > -1:
            return len(s[:s.find(" ")])
        else:
            return len(s)