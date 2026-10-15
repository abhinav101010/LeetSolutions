import java.util.*;
class Solution {
    public int[][] spiralMatrixIII(int R, int C, int r0, int c0) {
        int total = R * C;
        List<int[]> res = new ArrayList<>();
        res.add(new int[]{r0, c0});
        if (total == 1) {
            return res.toArray(new int[0][]);
        }
        int[][] dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        int dirIdx = 0;
        int step = 1;
        int r = r0, c = c0;
        while (res.size() < total) {
            for (int k = 0; k < 2; k++) {
                int dr = dirs[dirIdx][0];
                int dc = dirs[dirIdx][1];
                for (int s = 0; s < step; s++) {
                    r += dr;
                    c += dc;
                    if (r >= 0 && r < R && c >= 0 && c < C) {
                        res.add(new int[]{r, c});
                        if (res.size() == total) {
                            return res.toArray(new int[0][]);
                        }
                    }
                }
                dirIdx = (dirIdx + 1) % 4;
            }
            step++;
        }
        return res.toArray(new int[0][]);
    }
}
