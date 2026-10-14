import java.util.*;

class Solution {
    public int[] pourWater(int[] heights, int volume, int k) {
        int n = heights.length;
        for (int v = 0; v < volume; v++) {
            // try left
            int i = k;
            while (i > 0 && heights[i-1] <= heights[i]) {
                i--;
            }
            if (i < k && heights[i] < heights[k]) {
                heights[i]++;
                continue;
            }
            // try right
            i = k;
            while (i < n-1 && heights[i+1] <= heights[i]) {
                i++;
            }
            if (i > k && heights[i] < heights[k]) {
                heights[i]++;
                continue;
            }
            // stay
            heights[k]++;
        }
        return heights;
    }
}
