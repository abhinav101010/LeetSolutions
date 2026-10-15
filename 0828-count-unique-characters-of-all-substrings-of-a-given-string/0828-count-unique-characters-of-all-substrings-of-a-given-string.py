class Solution:
    def uniqueLetterString(self, s: str) -> int:
        # map char to list of indices
        indices = {}
        for i, ch in enumerate(s):
            indices.setdefault(ch, []).append(i)
        ans = 0
        for ch, pos in indices.items():
            # add sentinels at -1 and len(s)
            pos = [-1] + pos + [len(s)]
            for i in range(1, len(pos)-1):
                ans += (pos[i] - pos[i-1]) * (pos[i+1] - pos[i])
        return ans
