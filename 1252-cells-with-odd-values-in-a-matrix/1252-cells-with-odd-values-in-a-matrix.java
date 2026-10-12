class Solution {
    public int oddCells(int m, int n, int[][] indices) {
        int[] rows = new int[m];
        int[] cols = new int[n];

        for (int[] idx : indices) {
            rows[idx[0]]++;
            cols[idx[1]]++;
        }

        int ans = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if ((rows[r] + cols[c]) % 2 == 1) {
                    ans++;
                }
            }
        }

        return ans;
    }
}