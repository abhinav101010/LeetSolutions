class Solution:
    def numDistinct(self, s: str, t: str) -> int:
# Self thought but gives tle
        # ans = 0
        # def subsets(s, i, curr):
        #     nonlocal ans
        #     if curr == t:
        #         ans+=1
        #         return

        #     if i == len(s):
        #         return

        #     subsets(s, i + 1, curr)
        #     subsets(s, i + 1, curr + s[i])

        # subsets(s, 0, "")
        # return ans

        memo = {}
        def dfs(i, j):
            if j == len(t):
                return 1

            if i == len(s):
                return 0

            if (i, j) in memo:
                return memo[(i, j)]

            if s[i] == t[j]:
                memo[(i, j)] = dfs(i + 1, j + 1) + dfs(i + 1, j)
            else:
                memo[(i, j)] = dfs(i + 1, j)

            return memo[(i, j)]

        return dfs(0, 0)