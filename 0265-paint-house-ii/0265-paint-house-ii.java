class Solution {
    public int minCostII(int[][] costs) {
        if (costs == null || costs.length == 0 || costs[0].length == 0) {
            return 0;
        }
        int n = costs.length;
        int k = costs[0].length;
        int[] prev = new int[k];
        System.arraycopy(costs[0], 0, prev, 0, k);
        for (int i = 1; i < n; i++) {
            int[] curr = new int[k];
            int min1 = Integer.MAX_VALUE;
            int min2 = Integer.MAX_VALUE;
            int idx = -1;
            for (int j = 0; j < k; j++) {
                if (prev[j] < min1) {
                    min2 = min1;
                    min1 = prev[j];
                    idx = j;
                } else if (prev[j] < min2) {
                    min2 = prev[j];
                }
            }
            for (int j = 0; j < k; j++) {
                if (j == idx) {
                    curr[j] = min2 + costs[i][j];
                } else {
                    curr[j] = min1 + costs[i][j];
                }
            }
            prev = curr;
        }
        int min = Integer.MAX_VALUE;
        for (int val : prev) {
            if (val < min) {
                min = val;
            }
        }
        return min;
    }
}
