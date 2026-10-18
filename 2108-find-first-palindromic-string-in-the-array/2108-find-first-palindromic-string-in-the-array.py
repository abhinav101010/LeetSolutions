class Solution:
    def firstPalindrome(self, words):
        return next((w for w in words if w == w[::-1]), "")
