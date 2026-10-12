class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        newMat = []
        for i in range(len(matrix)):
            row = []
            for j in range(len(matrix)-1, -1, -1):
                print(matrix[j][i])
                row.append(matrix[j][i])
            newMat.append(row)
        matrix[:] = newMat