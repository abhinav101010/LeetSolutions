class Solution:
    def orderlyQueue(self, S: str, K: int) -> str:
        if K == 1:
            # find smallest rotation
            s2 = S + S
            n = len(S)
            best = s2[:n]
            for i in range(1, n):
                cand = s2[i:i+n]
                if cand < best:
                    best = cand
            return best
        else:
            char_array = list(S)
            char_array.sort()
            return ''.join(char_array)
