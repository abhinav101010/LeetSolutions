class Solution:
    def customSortString(self, order: str, s: str) -> str:
        from collections import Counter
        cnt = Counter(s)
        res = []
        for c in order:
            if c in cnt:
                res.append(c * cnt[c])
                del cnt[c]
        for c, v in cnt.items():
            res.append(c * v)
        return ''.join(res)
