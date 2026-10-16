from collections import Counter
class Solution:
    def numPairsDivisibleBy60(self, time):
        c = Counter()
        ans = 0
        for t in time:
            rem = t % 60
            ans += c[(60 - rem) % 60]
            c[rem] += 1
        return ans
