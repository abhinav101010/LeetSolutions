import java.util.*;

class Solution {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> res = new ArrayList<>();
        long prev = (long)lower - 1;
        for (int i = 0; i <= nums.length; i++) {
            long cur = i < nums.length ? (long)nums[i] : (long)upper + 1;
            if (cur > prev + 1) {
                long l = prev + 1;
                long r = cur - 1;
                if (l == r) {
                    res.add(String.valueOf(l));
                } else {
                    res.add(l + "->" + r);
                }
            }
            prev = cur;
        }
        return res;
    }
}