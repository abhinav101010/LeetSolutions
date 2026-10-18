class Solution:
    def processQueries(self, queries, m):
        p = list(range(1, m + 1))
        ans = []
        for v in queries:
            j = p.index(v)
            ans.append(j)
            p.pop(j)
            p.insert(0, v)
        return ans
