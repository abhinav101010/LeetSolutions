class Solution:
    def removeStones(self, stones: list[list[int]]) -> int:
        n = len(stones)
        parent = list(range(2 * 10001))  # rows 0..10000, columns 10001..20001
        def find(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        def union(a, b):
            ra, rb = find(a), find(b)
            if ra != rb:
                parent[rb] = ra
        for x, y in stones:
            union(x, y + 10001)
        # count distinct roots among stones
        roots = set()
        for x, y in stones:
            roots.add(find(x))
        return n - len(roots)
