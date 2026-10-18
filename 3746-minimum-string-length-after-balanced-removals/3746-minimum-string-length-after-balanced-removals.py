class Solution:
    def minLengthAfterRemovals(self, s):
        a = s.count("a")
        b = len(s) - a
        return abs(a - b)