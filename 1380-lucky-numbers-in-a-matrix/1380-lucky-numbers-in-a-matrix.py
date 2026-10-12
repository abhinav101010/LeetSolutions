class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        ans = []

        for i in range(len(matrix)):
            row_min = min(matrix[i])

            j = matrix[i].index(row_min)

            is_max = True

            for r in range(len(matrix)):
                if matrix[r][j] > row_min:
                    is_max = False
                    break

            if is_max:
                ans.append(row_min)

        return ans