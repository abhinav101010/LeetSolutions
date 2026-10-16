class Solution:
    def minDominoRotations(self, A, B):
        n = len(A)
        def check(x):
            rot_a = rot_b = 0
            for i in range(n):
                if A[i] != x and B[i] != x: return float('inf')
                elif A[i] != x: rot_a += 1
                elif B[i] != x: rot_b += 1
            return min(rot_a, rot_b)
        res = min(check(A[0]), check(B[0]))
        return res if res != float('inf') else -1
