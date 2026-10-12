import java.util.*;

class Solution {
    private int[][] rects;
    private int[] areas;
    private int total;
    private Random rand = new Random();

    public Solution(int[][] rects) {
        this.rects = rects;
        this.areas = new int[rects.length];
        this.total = 0;
        for (int i = 0; i < rects.length; i++) {
            int x1 = rects[i][0], y1 = rects[i][1];
            int x2 = rects[i][2], y2 = rects[i][3];
            int area = (x2 - x1 + 1) * (y2 - y1 + 1);
            total += area;
            areas[i] = total;
        }
    }

    public int[] pick() {
        int r = rand.nextInt(total) + 1;
        int left = 0, right = areas.length - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (areas[mid] < r) left = mid + 1;
            else right = mid;
        }
        
        int x1 = rects[left][0], y1 = rects[left][1];
        int x2 = rects[left][2], y2 = rects[left][3];
        int x = x1 + rand.nextInt(x2 - x1 + 1);
        int y = y1 + rand.nextInt(y2 - y1 + 1);
        return new int[]{x, y};
    }
}