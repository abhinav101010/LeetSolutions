import java.util.Arrays;
class Solution {
    public int minIncrementForUnique(int[] A) {
        if (A == null || A.length == 0) return 0;
        Arrays.sort(A);
        int ans = 0;
        int prev = A[0];
        for (int i = 1; i < A.length; i++) {
            if (A[i] <= prev) {
                ans += prev + 1 - A[i];
                prev = prev + 1;
            } else {
                prev = A[i];
            }
        }
        return ans;
    }
}
