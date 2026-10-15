import java.util.*;
class Solution {
    public int largestOverlap(int[][] img1, int[][] img2) {
        int n = img1.length;
        Map<String, Integer> count = new HashMap<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) {
                    for (int x = 0; x < n; x++) {
                        for (int y = 0; y < n; y++) {
                            if (img2[x][y] == 1) {
                                String key = (x - i) + "," + (y - j);
                                count.put(key, count.getOrDefault(key, 0) + 1);
                            }
                        }
                    }
                }
            }
        }
        int max = 0;
        for (int v : count.values()) {
            max = Math.max(max, v);
        }
        return max;
    }
}
