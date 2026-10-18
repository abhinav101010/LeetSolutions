import java.util.*;

public class Solution {
    public int maxVacationDays(int[][] flights, int[][] days) {
        int n = flights.length, k = days[0].length;
        int[][] dp = new int[k + 1][n];
        for (int[] row : dp) Arrays.fill(row, -1000000000);
        dp[0][0] = 0;
        for (int week = 1; week <= k; ++week) {
            for (int city = 0; city < n; ++city) {
                dp[week][city] = dp[week - 1][city];
                for (int prev = 0; prev < n; ++prev) {
                    if (flights[prev][city]) {
                        dp[week][city] = Math.max(dp[week][city], dp[week - 1][prev]);
                    }
                }
                dp[week][city] += days[city][week - 1];
            }
        }
        int res = 0;
        for (int city = 0; city < n; ++city) {
            res = Math.max(res, dp[k][city]);
        }
        return res;
    }
}
