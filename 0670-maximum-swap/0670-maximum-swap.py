class Solution:
    def maximumSwap(self, num: int) -> int:
        s = list(str(num))
        n = len(s)
        last = {int(c): i for i, c in enumerate(s)}
        for i in range(n):
            for d in range(9, int(s[i]), -1):
                if d in last and last[d] > i:
                    s[i], s[last[d]] = s[last[d]], s[i]
                    return int(''.join(s))
        return num