class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        memory = {}
        cols = len(obstacleGrid) -1
        rows = len(obstacleGrid[0]) -1
        def path(curCol, curRow):
            if (curCol, curRow) in memory:
                return memory[(curCol, curRow)]
            
            if obstacleGrid[0][0] == 1 or obstacleGrid[-1][-1] == 1:
                return 0
                
            if curCol == cols and curRow == rows:
                return 1


            ways = 0

            if curCol < cols and obstacleGrid[curCol+1][curRow] != 1:
                ways += path(curCol+1, curRow)
            
            if curRow < rows and obstacleGrid[curCol][curRow+1] != 1:
                ways += path(curCol, curRow+1)

            memory[(curCol, curRow)] = ways
            return ways
        return path(0,0)
        
