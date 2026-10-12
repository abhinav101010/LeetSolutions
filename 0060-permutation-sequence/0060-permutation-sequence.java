import java.util.*;

class Solution {
    public String getPermutation(int n, int k) {
        List<Integer> nums = new ArrayList<>();
        int fact = 1;
        for (int i = 1; i < n; i++) {
            fact *= i;
            nums.add(i);
        }
        nums.add(n);
        k -= 1;
        StringBuilder ans = new StringBuilder();
        while (!nums.isEmpty()) {
            int idx = k / fact;
            k %= fact;
            ans.append(nums.get(idx));
            nums.remove(idx);
            if (!nums.isEmpty()) {
                fact /= nums.size();
            }
        }
        return ans.toString();
    }
}
