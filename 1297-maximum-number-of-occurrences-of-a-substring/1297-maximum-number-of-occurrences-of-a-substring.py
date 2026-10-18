class Solution:
    def maxFreq(self, s, maxLetters, minSize, maxSize):
        ans = 0
        cnt = Counter()
        for i in range(len(s) - minSize + 1):
            t = s[i : i + minSize]
            ss = set(t)
            if len(ss) <= maxLetters:
                cnt[t] += 1
                ans = max(ans, cnt[t])
        return ans
