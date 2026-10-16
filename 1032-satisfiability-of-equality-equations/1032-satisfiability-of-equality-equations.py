class Solution:
    def equationsPossible(self, equations):
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        def union(x,y):
            parent[find(x)] = find(y)
        parent = {c:c for c in 'abcdefghijklmnopqrstuvwxyz'}
        # union == 
        for eq in equations:
            if eq[1]=='=':
                a,b = eq[0], eq[3]
                union(a,b)
        # check !=
        for eq in equations:
            if eq[1]=='!':
                a,b = eq[0], eq[3]
                if find(a) == find(b): return False
        return True
