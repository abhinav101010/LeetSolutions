import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int intersectionSizeTwo(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt((int[] a) -> a[1])
                                          .thenComparingInt(a -> a[0]));
        int ans = 0;
        int first = -2; // largest selected
        int second = -2; // second largest selected
        for (int[] interval : intervals) {
            int a = interval[0];
            int b = interval[1];
            if (second >= a) {
                continue;
            }
            if (first >= a) {
                ans++;
                second = b;
            } else {
                ans += 2;
                first = b - 1;
                second = b;
            }
        }
        return ans;
    }
}
