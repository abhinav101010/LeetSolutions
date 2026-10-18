class Solution:
    def isPrefixString(self, s, words):
        n, m = len(s), 0
        for i, w in enumerate(words):
            m += len(w)
            if m == n:
                return "".join(words[: i + 1]) == s
        return False
