class Solution {
    public int maxBuilding(int n, int[][] restrictions) {
        int m = restrictions.length;
        int[][] r = new int[m + 2][2];
        System.arraycopy(restrictions, 0, r, 0, m);
        r[m] = new int[]{1, 0};
        if (restrictions.length == 0 || restrictions[m - 1][0] != n) {
            r[m + 1] = new int[]{n, n - 1};
        } else {
            r[m + 1] = new int[]{0, 0};
        }
        java.util.Arrays.sort(r, (a, b) -> a[0] - b[0]);
        int len = r.length;
        if (r[len - 1][0] == 0) len--;

        for (int i = 1; i < len; i++) {
            int dist = r[i][0] - r[i - 1][0];
            r[i][1] = Math.min(r[i][1], r[i - 1][1] + dist);
        }

        for (int i = len - 2; i >= 0; i--) {
            int dist = r[i + 1][0] - r[i][0];
            r[i][1] = Math.min(r[i][1], r[i + 1][1] + dist);
        }

        int ans = 0;
        for (int i = 1; i < len; i++) {
            int x1 = r[i - 1][0], h1 = r[i - 1][1];
            int x2 = r[i][0], h2 = r[i][1];
            int dist = x2 - x1;
            int peak = (h1 + h2 + dist) / 2;
            ans = Math.max(ans, peak);
        }
        return ans;
    }
}