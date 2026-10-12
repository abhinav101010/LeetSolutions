import java.util.*;

class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> result = new ArrayList<>();
        for (int num : nums) {
            int idx = Math.abs(num) - 1;
            if (nums[idx] < 0) {
                result.add(Math.abs(num));
            } else {
                nums[idx] = -nums[idx];
            }
        }
        return result;
    }
}