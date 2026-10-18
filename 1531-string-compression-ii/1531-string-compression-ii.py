class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        n = len(s)
        dp = {}
        
        def dfs(i: int, k: int) -> int:
            if (i, k) in dp:
                return dp[(i, k)]
            if i == n or n - i <= k:
                return 0
            ans = inf
            count = defaultdict(int)
            maxFreq = 0
            for j in range(i, n):
                c = s[j]
                count[c] += 1
                maxFreq = max(maxFreq, count[c])
                ans = min(ans, getLen(maxFreq) + dfs(j + 1, k - (j - i + 1 - maxFreq)))
            dp[(i, k)] = ans
            return ans
        
        def getLen(freq: int) -> int:
            if freq == 1:
                return 1
            if freq < 10:
                return 2
            if freq < 100:
                return 3
            return 4
        
        return dfs(0, k)

