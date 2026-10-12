class Solution:
    def isSelfCrossing(self, x: List[int]) -> bool:
        n = len(x)
        if n < 4:
            return False
        
        for i in range(3, n):
            # Case 1: Fourth line crosses first
            if x[i] >= x[i-2] and x[i-1] <= x[i-3]:
                return True
            # Case 2: Fifth line meets first
            if i >= 4 and x[i-1] == x[i-3] and x[i] + x[i-4] >= x[i-2]:
                return True
            # Case 3: Sixth line crosses first
            if i >= 5 and x[i-2] >= x[i-4] and x[i] + x[i-4] >= x[i-2] and x[i-1] <= x[i-3] and x[i-1] + x[i-5] >= x[i-3]:
                return True
        
        return False