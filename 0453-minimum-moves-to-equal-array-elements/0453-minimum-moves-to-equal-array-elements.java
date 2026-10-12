import java.util.*;

class Solution {
    public int minMoves(int[] nums) {
        int minVal = Arrays.stream(nums).min().getAsInt();
        int sum = 0;
        for (int num : nums) sum += num;
        return sum - minVal * nums.length;
    }
}