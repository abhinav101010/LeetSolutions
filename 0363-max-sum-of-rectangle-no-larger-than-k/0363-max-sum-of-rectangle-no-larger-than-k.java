import java.util.*;

class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int m = matrix.length, n = matrix[0].length;
        int maxSum = Integer.MIN_VALUE;
        
        for (int left = 0; left < n; left++) {
            int[] rowSums = new int[m];
            for (int right = left; right < n; right++) {
                for (int i = 0; i < m; i++) {
                    rowSums[i] += matrix[i][right];
                }
                
                TreeSet<Integer> sortedPrefix = new TreeSet<>();
                sortedPrefix.add(0);
                int prefix = 0;
                for (int s : rowSums) {
                    prefix += s;
                    Integer target = sortedPrefix.ceiling(prefix - k);
                    if (target != null) {
                        maxSum = Math.max(maxSum, prefix - target);
                    }
                    sortedPrefix.add(prefix);
                }
            }
        }
        
        return maxSum;
    }
}