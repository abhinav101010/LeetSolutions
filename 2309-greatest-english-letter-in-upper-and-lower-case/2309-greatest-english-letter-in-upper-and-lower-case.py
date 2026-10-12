class Solution:
    def greatestLetter(self, s: str) -> str:
        ans = ""
        for c in "abcdefghijklmnopqrstuvwxyz":
            if c in s and c.upper() in s:
                ans = c.upper()
        return ans