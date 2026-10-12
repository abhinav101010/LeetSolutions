class Solution:
    def magicalString(self, n: int) -> int:
        if n <= 3:
            return 1
        
        s = [1, 2, 2]
        i = 2
        while len(s) < n:
            next_val = 3 - s[-1]  # alternate between 1 and 2
            s.extend([next_val] * s[i])
            i += 1
        
        return s[:n].count(1)