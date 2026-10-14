import java.util.*;

class Solution {
    public int deleteAndEarn(int[] nums) {
        if (nums.length == 0) return 0;
        int max = 0;
        for (int x : nums) {
            if (x > max) max = x;
        }
        int[] freq = new int[max + 1];
        for (int x : nums) {
            freq[x] += x;
        }
        int take = 0;
        int skip = 0;
        for (int v : freq) {
            int newTake = skip + v;
            int newSkip = Math.max(take, skip);
            take = newTake;
            skip = newSkip;
        }
        return Math.max(take, skip);
    }
}
