import java.util.*;
class Solution {
    public int[] advantageCount(int[] A, int[] B) {
        int n = A.length;
        int[] sortedA = Arrays.copyOf(A, n);
        Arrays.sort(sortedA);
        int[][] sortedB = new int[n][2];
        for (int i = 0; i < n; i++) {
            sortedB[i][0] = B[i];
            sortedB[i][1] = i;
        }
        Arrays.sort(sortedB, (a, b) -> Integer.compare(a[0], b[0]));
        int[] res = new int[n];
        int left = 0, right = n-1;
        for (int k = n-1; k >= 0; k--) {
            int b = sortedB[k][0];
            int idx = sortedB[k][1];
            if (sortedA[right] > b) {
                res[idx] = sortedA[right];
                right--;
            } else {
                res[idx] = sortedA[left];
                left++;
            }
        }
        return res;
    }
}
