import java.util.*;

class Solution {
    public int[] smallestRange(int[][] nums) {
        int k = nums.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        int maxVal = -1000000000;
        for (int i = 0; i < k; i++) {
            pq.offer(new int[]{nums[i][0], i, 0});
            maxVal = Math.max(maxVal, nums[i][0]);
        }
        
        int[] ans = new int[]{pq.peek()[0], maxVal};
        while (true) {
            int[] cur = pq.poll();
            int rowIdx = cur[1];
            int colIdx = cur[2];
            if (colIdx + 1 == nums[rowIdx].length) break;
            int nextVal = nums[rowIdx][colIdx + 1];
            pq.offer(new int[]{nextVal, rowIdx, colIdx + 1});
            maxVal = Math.max(maxVal, nextVal);
            if (maxVal - pq.peek()[0] < ans[1] - ans[0]) {
                ans[0] = pq.peek()[0];
                ans[1] = maxVal;
            }
        }
        
        return ans;
    }
}