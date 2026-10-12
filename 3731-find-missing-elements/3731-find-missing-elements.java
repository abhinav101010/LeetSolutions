import java.util.*;

class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        int n = nums.length;
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        Set<Integer> set = new HashSet<>();
        for (int x : nums) {
            set.add(x);
            if (x < min) min = x;
            if (x > max) max = x;
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = min; i <= max; i++) {
            if (!set.contains(i)) ans.add(i);
        }
        return ans;
    }
}