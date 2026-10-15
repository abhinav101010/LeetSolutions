import java.util.*;
class Solution {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        List<Integer> res = new ArrayList<>();
        if (bound < 1) return res;
        List<Integer> xs = new ArrayList<>();
        int xi = 1;
        while (true) {
            xs.add(xi);
            if (x == 1) break;
            xi *= x;
            if (xi > bound) break;
        }
        List<Integer> ys = new ArrayList<>();
        int yi = 1;
        while (true) {
            ys.add(yi);
            if (y == 1) break;
            yi *= y;
            if (yi > bound) break;
        }
        Set<Integer> set = new HashSet<>();
        for (int a : xs) {
            for (int b : ys) {
                int s = a + b;
                if (s <= bound) {
                    set.add(s);
                } else {
                    break;
                }
            }
        }
        res.addAll(set);
        return res;
    }
}
