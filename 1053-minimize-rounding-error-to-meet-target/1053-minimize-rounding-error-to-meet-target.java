import java.util.*;
class Solution {
    public String minRoundingError(String[] prices, int target) {
        List<Double> diff = new ArrayList<>();
        long low = 0, high = 0;
        for (String s : prices) {
            double f = Double.parseDouble(s);
            long i = (long)Math.floor(f);
            low += i;
            if (f == i) {
                high += i;
                diff.add(0.0);
            } else {
                high += i + 1;
                diff.add(Math.min(f-i, i+1-f));
            }
        }
        if (target < low || target > high) return "-1";
        long need = target - low;
        Collections.sort(diff);
        double res = 0;
        for (double d : diff) res += d;
        for (int k=0;k<need;k++) {
            double d = diff.get(k);
            res = res - d + (1-d);
        }
        return String.format("%.3f", res);
    }
}
