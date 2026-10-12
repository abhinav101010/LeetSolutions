class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        topRow = 0
        bottomRow = len(matrix) - 1

        while topRow <= bottomRow:
            midRow = (topRow + bottomRow)//2

            if matrix[midRow][0] <= target <= matrix[midRow][-1]:
                left = 0
                right = len(matrix[0])-1
                
                while left <= right:
                    mid = (left + right) // 2
                    if matrix[midRow][mid] == target:
                        return True
                    elif matrix[midRow][mid] < target:
                        left = mid + 1
                    else:
                        right = mid - 1
                return False
            else:
                if matrix[midRow][-1] < target: topRow = midRow+1
                elif matrix[midRow][0] > target: bottomRow = midRow-1
        return False
            













