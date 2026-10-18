class Solution:
    def removePalindromeSub(self, s) -> int:
        return 1 if s[::-1] == s else 2
