import java.util.*;

class Solution {
    public List<Integer> fallingSquares(int[][] positions) {
        List<Integer> res = new ArrayList<>();
        List<int[]> squares = new ArrayList<>(); // each as {left, right, height}
        int curMax = 0;
        for (int[] pos : positions) {
            int left = pos[0];
            int side = pos[1];
            int right = left + side;
            int base = 0;
            for (int[] sq : squares) {
                int l = sq[0], r = sq[1], h = sq[2];
                if (!(r <= left || right <= l)) { // overlap
                    base = Math.max(base, h);
                }
            }
            int h = base + side;
            squares.add(new int[]{left, right, h});
            curMax = Math.max(curMax, h);
            res.add(curMax);
        }
        return res;
    }
}
