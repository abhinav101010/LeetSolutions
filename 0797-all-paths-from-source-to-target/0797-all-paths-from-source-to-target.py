class Solution:
    def allPathsSourceTarget(self, graph: list[list[int]]) -> list[list[int]]:
        n = len(graph)
        target = n - 1
        result = []
        path = [0]
        def dfs(u):
            if u == target:
                result.append(path.copy())
                return
            for v in graph[u]:
                path.append(v)
                dfs(v)
                path.pop()
        dfs(0)
        return result
