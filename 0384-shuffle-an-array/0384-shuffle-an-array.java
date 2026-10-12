import java.util.*;

class Solution {
    private int[] original;
    private int[] nums;
    private Random rand;
    
    public Solution(int[] nums) {
        original = nums.clone();
        this.nums = nums.clone();
        rand = new Random();
    }
    
    public int[] reset() {
        nums = original.clone();
        return nums;
    }
    
    public int[] shuffle() {
        for (int i = nums.length - 1; i > 0; i--) {
            int j = rand.nextInt(i + 1);
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        return nums;
    }
}