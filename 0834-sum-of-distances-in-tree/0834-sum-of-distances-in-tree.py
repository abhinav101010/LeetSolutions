class Solution:
    def sumOfDistancesInTree(self, n: int, edges: list[list[int]]) -> list[int]:
        from collections import defaultdict
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        count = [1] * n  # number of nodes in subtree rooted at node
        ans = [0] * n    # sum of distances from node to all nodes in its subtree
        # first dfs: post-order
        def dfs(u, parent):
            for v in graph[u]:
                if v == parent:
                    continue
                dfs(v, u)
                count[u] += count[v]
                ans[u] += ans[v] + count[v]
        dfs(0, -1)
        # second dfs: pre-order
        def dfs2(u, parent):
            for v in graph[u]:
                if v == parent:
                    continue
                ans[v] = ans[u] - count[v] + (n - count[v])
                dfs2(v, u)
        dfs2(0, -1)
        return ans
