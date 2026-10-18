class Solution:
    def mergeCharacters(self, s, k) -> str:
        last = {}
        ans = []
        for c in s:
            cur = len(ans)
            if c in last and cur - last[c] <= k:
                continue
            ans.append(c)
            last[c] = cur
        return "".join(ans)
