from typing import List

class Solution:
    def isConvex(self, points: List[List[int]]) -> bool:
        n = len(points)
        def cross(A, B, C):
            # (B-A) x (C-B)
            x1 = B[0] - A[0]
            y1 = B[1] - A[1]
            x2 = C[0] - B[0]
            y2 = C[1] - B[1]
            return x1 * y2 - y1 * x2
        # We'll compute sign of cross product for each triplet
        sign = 0
        for i in range(n):
            A = points[i]
            B = points[(i+1)%n]
            C = points[(i+2)%n]
            cp = cross(A, B, C)
            if cp != 0:
                if sign == 0:
                    sign = 1 if cp > 0 else -1
                else:
                    if (cp > 0 and sign < 0) or (cp < 0 and sign > 0):
                        return False
        return True
