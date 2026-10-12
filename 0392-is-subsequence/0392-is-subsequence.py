class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        prev = -1
        for i in range(len(s)):
            curr = t.find(s[i], prev + 1)
            if curr == -1:
                return False
            prev = curr
        return True