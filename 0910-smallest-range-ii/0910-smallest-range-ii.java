import java.util.Arrays;
class Solution {
    public int smallestRangeII(int[] A, int K) {
        Arrays.sort(A);
        int n = A.length;
        int ans = A[n-1] - A[0];
        for (int i = 0; i < n-1; i++) {
            int high = Math.max(A[i] + K, A[n-1] - K);
            int low = Math.min(A[0] + K, A[i+1] - K);
            ans = Math.min(ans, high - low);
        }
        return ans;
    }
}
