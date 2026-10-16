class Solution:
    def commonChars(self, A):
        if not A: return []
        res = list(A[0])
        for word in A[1:]:
            new_res = []
            for c in word:
                if c in res:
                    new_res.append(c)
                    res.remove(c)
            res = new_res
            if not res: break
        return res
