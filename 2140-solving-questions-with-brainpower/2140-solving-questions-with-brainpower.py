class Solution:
    def mostPoints(self, questions]):
        @cache
        def dfs(i):
            if i >= len(questions):
                return 0
            p, b = questions[i]
            return max(p + dfs(i + b + 1), dfs(i + 1))

        return dfs(0)
