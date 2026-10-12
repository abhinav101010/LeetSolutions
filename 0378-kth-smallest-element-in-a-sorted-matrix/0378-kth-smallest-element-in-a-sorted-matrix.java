import java.util.*;

class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        
        for (int i = 0; i < Math.min(k, n); i++) {
            pq.offer(new int[]{matrix[i][0], i, 0});
        }
        
        int result = 0;
        for (int i = 0; i < k; i++) {
            int[] curr = pq.poll();
            result = curr[0];
            int row = curr[1], col = curr[2];
            if (col + 1 < n) {
                pq.offer(new int[]{matrix[row][col + 1], row, col + 1});
            }
        }
        
        return result;
    }
}