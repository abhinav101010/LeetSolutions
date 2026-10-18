class Solution:
    def maxTotalReward(self, rewardValues):
        @cache
        def dfs(x):
            i = bisect_right(rewardValues, x)
            ans = 0
            for v in rewardValues[i:]:
                ans = max(ans, v + dfs(x + v))
            return ans

        rewardValues.sort()
        return dfs(0)
