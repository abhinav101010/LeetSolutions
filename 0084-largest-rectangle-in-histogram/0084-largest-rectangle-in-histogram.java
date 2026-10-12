import java.util.*;

class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<int[]> stack = new Stack<>(); // {index, height}
        int maxArea = 0;
        
        for (int i = 0; i < heights.length; i++) {
            int start = i;
            while (!stack.isEmpty() && stack.peek()[1] > heights[i]) {
                int[] prev = stack.pop();
                int area = prev[1] * (i - prev[0]);
                maxArea = Math.max(maxArea, area);
                start = prev[0];
            }
            stack.push(new int[]{start, heights[i]});
        }
        
        int n = heights.length;
        while (!stack.isEmpty()) {
            int[] prev = stack.pop();
            int area = prev[1] * (n - prev[0]);
            maxArea = Math.max(maxArea, area);
        }
        
        return maxArea;
    }
}