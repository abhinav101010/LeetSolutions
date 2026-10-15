class Solution:
    def numSimilarGroups(self, strs: list[str]) -> int:
        n = len(strs)
        parent = list(range(n))
        rank = [0] * n
        def find(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        def union(x, y):
            rx, ry = find(x), find(y)
            if rx == ry:
                return
            if rank[rx] < rank[ry]:
                parent[rx] = ry
            elif rank[rx] > rank[ry]:
                parent[ry] = rx
            else:
                parent[ry] = rx
                rank[rx] += 1
        def similar(a, b):
            if a == b:
                return True
            diff = []
            for i in range(len(a)):
                if a[i] != b[i]:
                    diff.append(i)
                    if len(diff) > 2:
                        return False
            return len(diff) == 2 and a[diff[0]] == b[diff[1]] and a[diff[1]] == b[diff[0]]
        for i in range(n):
            for j in range(i+1, n):
                if similar(strs[i], strs[j]):
                    union(i, j)
        # count distinct roots
        roots = set()
        for i in range(n):
            roots.add(find(i))
        return len(roots)
