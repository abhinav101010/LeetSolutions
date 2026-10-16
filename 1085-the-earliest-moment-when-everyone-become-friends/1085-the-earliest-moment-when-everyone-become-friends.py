class Solution:
    def earliestAcq(self, logs, N):
        logs.sort()
        parent = list(range(N))
        comp = N
        def find(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        for t, a, b in logs:
            ra, rb = find(a), find(b)
            if ra != rb:
                parent[ra] = rb
                comp -= 1
                if comp == 1:
                    return t
        return -1
