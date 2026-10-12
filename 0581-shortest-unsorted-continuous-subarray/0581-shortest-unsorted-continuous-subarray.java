import java.util.*;

class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int[] sorted = nums.clone();
        Arrays.sort(sorted);
        int left = 0, right = nums.length - 1;
        while (left < nums.length && nums[left] == sorted[left]) left++;
        while (right > left && nums[right] == sorted[right]) right--;
        return right > left ? right - left + 1 : 0;
    }
}