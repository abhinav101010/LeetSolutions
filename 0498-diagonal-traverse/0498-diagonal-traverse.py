from typing import List

class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        if not mat or not mat[0]:
            return []
        m, n = len(mat), len(mat[0])
        result = []
        
        for d in range(m + n - 1):
            if d % 2 == 0:
                r = d if d < m else m - 1
                c = d - r
                while r >= 0 and c < n:
                    result.append(mat[r][c])
                    r -= 1
                    c += 1
            else:
                c = d if d < n else n - 1
                r = d - c
                while c >= 0 and r < m:
                    result.append(mat[r][c])
                    r += 1
                    c -= 1
        
        return result