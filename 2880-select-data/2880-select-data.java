import java.util.*;

class Solution {
    public List<Integer> selectData(int[] nums, int target) {
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) res.add(i);
        }
        return res;
    }
}
