from typing import List

class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        n = len(row)
        # couple id: person // 2
        dsu = list(range(n//2))
        def find(x):
            while dsu[x] != x:
                dsu[x] = dsu[dsu[x]]
                x = dsu[x]
            return x
        def union(a, b):
            ra, rb = find(a), find(b)
            if ra != rb:
                dsu[ra] = rb
        for i in range(0, n, 2):
            a = row[i] // 2
            b = row[i+1] // 2
            union(a, b)
        # count number of distinct roots
        roots = set()
        for i in range(n//2):
            roots.add(find(i))
        return (n//2) - len(roots)
