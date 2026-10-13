from typing import List

class Solution:
    def multiply(self, mat1: List[List[int]], mat2: List[List[int]]) -> List[List[int]]:
        m = len(mat1)
        k = len(mat1[0]) if m > 0 else 0
        n = len(mat2[0]) if k > 0 else 0
        res = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(k):
                if mat1[i][j] != 0:
                    for l in range(n):
                        if mat2[j][l] != 0:
                            res[i][l] += mat1[i][j] * mat2[j][l]
        return res