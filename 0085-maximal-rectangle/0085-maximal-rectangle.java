import java.util.*;

class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        
        int m = matrix.length;
        int n = matrix[0].length;
        int[] heights = new int[n];
        int maxArea = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            
            // Largest rectangle in histogram
            Stack<int[]> stack = new Stack<>();
            for (int k = 0; k < n; k++) {
                int start = k;
                while (!stack.isEmpty() && stack.peek()[1] > heights[k]) {
                    int[] prev = stack.pop();
                    int area = prev[1] * (k - prev[0]);
                    maxArea = Math.max(maxArea, area);
                    start = prev[0];
                }
                stack.push(new int[]{start, heights[k]});
            }
            
            while (!stack.isEmpty()) {
                int[] prev = stack.pop();
                int area = prev[1] * (n - prev[0]);
                maxArea = Math.max(maxArea, area);
            }
        }
        
        return maxArea;
    }
}