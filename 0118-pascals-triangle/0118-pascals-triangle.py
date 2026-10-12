class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1: return [[1]]
        if numRows == 2: return [[1], [1,1]]

        ans = [[1], [1,1]]
        prevRow = [1,1]
        for i in range(3, numRows+1):
            first = 0
            second = 1
            row = []
            for j in range(0, i):
                if j == 0 or j == i-1:
                    row.append(1)
                    continue
                row.append(prevRow[first]+prevRow[second])
                first+=1
                second+=1
            ans.append(row)
            prevRow = row
        return ans