class Solution:
    def maxFreqSum(self, s):
        cnt = Counter(s)
        a = b = 0
        for c, v in cnt.items():
            if c in "aeiou":
                a = max(a, v)
            else:
                b = max(b, v)
        return a + b
