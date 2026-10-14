import java.util.List;

class Solution {
    public boolean isConvex(List<List<Integer>> points) {
        int n = points.size();
        if (n < 3) return false;
        long sign = 0;
        for (int i = 0; i < n; i++) {
            List<Integer> A = points.get(i);
            List<Integer> B = points.get((i+1)%n);
            List<Integer> C = points.get((i+2)%n);
            long x1 = B.get(0) - A.get(0);
            long y1 = B.get(1) - A.get(1);
            long x2 = C.get(0) - B.get(0);
            long y2 = C.get(1) - B.get(1);
            long cp = x1 * y2 - y1 * x2;
            if (cp != 0) {
                if (sign == 0) {
                    sign = cp > 0 ? 1 : -1;
                } else {
                    if ((cp > 0 && sign < 0) || (cp < 0 && sign > 0)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
