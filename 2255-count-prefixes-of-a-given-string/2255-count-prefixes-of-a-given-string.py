class Solution:
    def countPrefixes(self, words, s):
        return sum(s.startswith(w) for w in words)
