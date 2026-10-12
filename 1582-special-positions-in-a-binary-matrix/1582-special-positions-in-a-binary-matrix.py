class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        rows = [0] * len(mat)
        cols = [0] * len(mat[0])

        # Count 1s in each row and column
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if mat[i][j] == 1:
                    rows[i] += 1
                    cols[j] += 1

        ans = 0

        # Count special positions
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if mat[i][j] == 1 and rows[i] == 1 and cols[j] == 1:
                    ans += 1

        return ans