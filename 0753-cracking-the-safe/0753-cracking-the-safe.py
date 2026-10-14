class Solution:
    def crackSafe(self, n: int, k: int) -> str:
        if n == 1:
            return ''.join(str(i) for i in range(k))
        visited = set()
        ans = []
        # node is string of length n-1
        def dfs(node):
            for x in map(str, range(k)):
                edge = node + x
                if edge not in visited:
                    visited.add(edge)
                    dfs(edge[1:])  # next node is suffix of length n-1
                    ans.append(x)
        start = '0' * (n-1)
        dfs(start)
        return start + ''.join(reversed(ans))
