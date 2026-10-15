class Solution {
    public int partitionArrayDisjoint(int[] A) {
        int n = A.length;
        int[] maxLeft = new int[n];
        int[] minRight = new int[n];
        maxLeft[0] = A[0];
        for (int i = 1; i < n; i++) {
            maxLeft[i] = Math.max(maxLeft[i-1], A[i]);
        }
        minRight[n-1] = A[n-1];
        for (int i = n-2; i >= 0; i--) {
            minRight[i] = Math.min(minRight[i+1], A[i]);
        }
        for (int i = 0; i < n-1; i++) {
            if (maxLeft[i] <= minRight[i+1]) {
                return i+1;
            }
        }
        return n;
    }
}
