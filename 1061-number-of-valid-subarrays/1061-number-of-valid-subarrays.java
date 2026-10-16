import java.util.*;
class Solution {
    public int validSubarrays(int[] nums) {
        int ans = 0;
        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = 0; i < nums.length; i++) {
            while (!stack.isEmpty() && nums[stack.peek()] > nums[i]) {
                stack.pop();
            }
            stack.push(i);
            ans += stack.size();
        }
        return ans;
    }
}
