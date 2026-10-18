class Solution:
    def longestSubsequence(self, arr, difference):
        f = defaultdict(int)
        for x in arr:
            f[x] = f[x - difference] + 1
        return max(f.values())
