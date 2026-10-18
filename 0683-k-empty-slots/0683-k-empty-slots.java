import java.util.*;

class Solution {
    public int kEmptySlots(int[] bulbs, int k) {
        int n = bulbs.length;
        if (n == 0) return -1;
        int[] days = new int[n + 1]; // 1-indexed positions
        for (int day = 1; day <= n; day++) {
            int pos = bulbs[day - 1];
            days[pos] = day;
        }
        int window = k + 2;
        if (window > n) return -1;
        int m = n - window + 1; // number of windows
        // arr = days[2..n-1] inclusive, length n-2
        int[] arr = new int[n - 2];
        for (int i = 0; i < n - 2; i++) {
            arr[i] = days[i + 2];
        }
        // sliding window minimum of size k over arr
        Deque<Integer> dq = new ArrayDeque<>();
        int[] minArr = new int[m]; // length m
        for (int i = 0; i < arr.length; i++) {
            while (!dq.isEmpty() && arr[dq.peekLast()] >= arr[i]) {
                dq.pollLast();
            }
            dq.offerLast(i);
            if (dq.peekFirst() <= i - k) {
                dq.pollFirst();
            }
            if (i >= k - 1) {
                minArr[i - k + 1] = arr[dq.peekFirst()];
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int l = 1; l <= m; l++) {
            int interiorMin = minArr[l - 1];
            int leftDay = days[l];
            int rightDay = days[l + k + 1];
            if (interiorMin > Math.max(leftDay, rightDay)) {
                int cand = Math.max(leftDay, rightDay);
                if (cand < ans) {
                    ans = cand;
                }
            }
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}
