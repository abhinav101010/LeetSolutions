class Solution:
    def largest1BorderedSquare(self, grid):
        m=len(grid); n=len(grid[0])
        up=[[0]*n for _ in range(m)]; left=[[0]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    up[i][j]=(up[i-1][j] if i else 0)+1
                    left[i][j]=(left[i][j-1] if j else 0)+1
        best=0
        for i in range(m):
            for j in range(n):
                for k in range(min(up[i][j],left[i][j]),0,-1):
                    if k<=best: break
                    if up[i][j-k+1]>=k and left[i-k+1][j]>=k:
                        best=k; break
        return best*best
