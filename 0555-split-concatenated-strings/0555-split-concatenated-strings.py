class Solution:
    def splitLoopedString(self, strs: List[str]) -> str:
        n = len(strs)
        s = [max(a, a[::-1]) for a in strs]
        res = ''
        for i, t in enumerate(strs):
            for cur in (t, t[::-1]):
                for j in range(len(cur)):
                    candidate = cur[j:] + ''.join(s[(i + k) % n] for k in range(1, n)) + cur[:j]
                    if candidate > res:
                        res = candidate
        return res
