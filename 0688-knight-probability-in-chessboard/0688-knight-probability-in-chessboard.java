class Solution {
    public double knightProbability(int n, int k, int row, int column) {
        double[][] dp = new double[n][n];
        dp[row][column] = 1;
        int[][] dirs = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
        for (int step = 0; step < k; step++) {
            double[][] newDp = new double[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[i][j] == 0) continue;
                    for (int[] d : dirs) {
                        int ni = i + d[0], nj = j + d[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            newDp[ni][nj] += dp[i][j] / 8.0;
                        }
                    }
                }
            }
            dp = newDp;
        }
        double res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) res += dp[i][j];
        }
        return res;
    }
}