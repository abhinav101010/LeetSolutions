class Solution:
    def loudAndRich(self, richer: list[list[int]], quiet: list[int]) -> list[int]:
        n = len(quiet)
        adj = [[] for _ in range(n)]  # adj[v] = list of u such that u -> v (u richer than v)
        for u, v in richer:
            adj[v].append(u)
        ans = [-1] * n
        def dfs(v):
            if ans[v] != -1:
                return ans[v]
            best = quiet[v]
            best_person = v
            for u in adj[v]:
                cand = dfs(u)
                if quiet[cand] < best:
                    best = quiet[cand]
                    best_person = cand
            ans[v] = best_person
            return ans[v]
        for i in range(n):
            dfs(i)
        return ans
