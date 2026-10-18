class Solution:
    def isPossibleToRearrange(self, s, t, k) :
        cnt = Counter()
        n = len(s)
        m = n // k
        for i in range(0, n, m):
            cnt[s[i : i + m]] += 1
            cnt[t[i : i + m]] -= 1
        return all(v == 0 for v in cnt.values())
