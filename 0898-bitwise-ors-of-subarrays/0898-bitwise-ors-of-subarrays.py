class Solution:
    def subarrayBitwiseORs(self, A: list[int]) -> int:
        res = set()
        cur = set()
        for x in A:
            cur = {x | y for y in cur} | {x}
            res.update(cur)
        return len(res)
