from typing import List

class Solution:
    def findPermutation(self, s: str) -> List[int]:
        n = len(s) + 1
        res = list(range(1, n+1))
        i = 0
        while i < len(s):
            if s[i] == 'I':
                i += 1
                continue
            # start of D sequence
            j = i
            while j < len(s) and s[j] == 'D':
                j += 1
            # reverse res[i:j+1]
            l, r = i, j
            while l < r:
                res[l], res[r] = res[r], res[l]
                l += 1
                r -= 1
            i = j
        return res
