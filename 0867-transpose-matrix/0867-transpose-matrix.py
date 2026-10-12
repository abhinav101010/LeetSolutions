class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        matrixT = [[0] * len(matrix) for _ in range(len(matrix[0]))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                matrixT[j][i] = matrix[i][j]
        return matrixT