import java.util.*;

class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) return 0;
        
        int m = matrix.length, n = matrix[0].length;
        int[][] memo = new int[m][n];
        int[][] dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = Math.max(result, dfs(matrix, i, j, memo, dirs));
            }
        }
        return result;
    }
    
    private int dfs(int[][] matrix, int i, int j, int[][] memo, int[][] dirs) {
        if (memo[i][j] != 0) return memo[i][j];
        
        int maxLen = 1;
        for (int[] d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && ni < matrix.length && nj >= 0 && nj < matrix[0].length && matrix[ni][nj] > matrix[i][j]) {
                maxLen = Math.max(maxLen, 1 + dfs(matrix, ni, nj, memo, dirs));
            }
        }
        
        memo[i][j] = maxLen;
        return maxLen;
    }
}