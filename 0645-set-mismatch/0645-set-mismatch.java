import java.util.Arrays;

class Solution {
    public int[] findErrorNums(int[] nums) {
        Arrays.sort(nums);
        int duplicate = -1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1]) {
                duplicate = nums[i];
                break;
            }
        }
        for (int i = 1; i <= nums.length; i++) {
            boolean found = false;
            for (int j = 0; j < nums.length; j++) {
                if (nums[j] == i) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return new int[]{duplicate, i};
            }
        }
        return new int[]{duplicate, nums.length};
    }
}
