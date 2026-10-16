class Solution:
    def smallestEquivalentString(self, s1, s2, baseStr):
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        parent = list(range(26))
        for c1,c2 in zip(s1,s2):
            p1 = find(ord(c1)-ord('a'))
            p2 = find(ord(c2)-ord('a'))
            if p1 < p2: parent[p2] = p1
            else: parent[p1] = p2
        res = []
        for c in baseStr:
            p = find(ord(c)-ord('a'))
            res.append(chr(ord('a')+p))
        return ''.join(res)
