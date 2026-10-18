class Solution:
    def reversePrefix(self, s, k):
        return s[:k][::-1] + s[k:]
