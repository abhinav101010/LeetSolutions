import java.util.*;
class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int n = difficulty.length;
        int[][] jobs = new int[n][2];
        for (int i = 0; i < n; i++) {
            jobs[i][0] = difficulty[i];
            jobs[i][1] = profit[i];
        }
        Arrays.sort(jobs, (a, b) -> Integer.compare(a[0], b[0]));
        int[] maxProfitUpTo = new int[n];
        int maxp = 0;
        for (int i = 0; i < n; i++) {
            maxp = Math.max(maxp, jobs[i][1]);
            maxProfitUpTo[i] = maxp;
        }
        int[] diffs = new int[n];
        for (int i = 0; i < n; i++) {
            diffs[i] = jobs[i][0];
        }
        int ans = 0;
        for (int w : worker) {
            int idx = binarySearch(diffs, w);
            if (idx >= 0) {
                ans += maxProfitUpTo[idx];
            }
        }
        return ans;
    }
    private int binarySearch(int[] arr, int target) {
        int lo = 0, hi = arr.length - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] <= target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return hi;
    }
}
