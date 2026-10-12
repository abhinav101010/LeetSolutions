class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        if (ops.length == 0) {
            return m * n;
        }
        int minRow = m;
        int minCol = n;
        for (int i = 0; i < ops.length; i++) {
            if (ops[i][0] < minRow) {
                minRow = ops[i][0];
            }
            if (ops[i][1] < minCol) {
                minCol = ops[i][1];
            }
        }
        return minRow * minCol;
    }
}