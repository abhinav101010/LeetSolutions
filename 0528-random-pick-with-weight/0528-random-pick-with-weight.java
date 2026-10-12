import java.util.*;

class Solution {
    private int[] prefix;
    private Random rand = new Random();

    public Solution(int[] w) {
        prefix = new int[w.length];
        int total = 0;
        for (int i = 0; i < w.length; i++) {
            total += w[i];
            prefix[i] = total;
        }
    }

    public int pickIndex() {
        int target = rand.nextInt(prefix[prefix.length - 1]) + 1;
        int left = 0, right = prefix.length - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (prefix[mid] < target) left = mid + 1;
            else right = mid;
        }
        return left;
    }
}