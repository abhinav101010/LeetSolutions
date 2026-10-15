import java.util.*;
class Solution {
    public int maxWidthRamp(int[] A) {
        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = 0; i < A.length; i++) {
            if (stack.isEmpty() || A[i] < A[stack.peek()]) {
                stack.push(i);
            }
        }
        int ans = 0;
        for (int j = A.length - 1; j >= 0; j--) {
            while (!stack.isEmpty() && A[stack.peek()] <= A[j]) {
                ans = Math.max(ans, j - stack.pop());
            }
        }
        return ans;
    }
}
