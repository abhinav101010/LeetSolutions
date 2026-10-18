import java.util.*;
class Solution {
    private int ans;
    public int numSquarefulPerms(int[] nums) {
        Arrays.sort(nums);
        ans = 0;
        boolean[] used = new boolean[nums.length];
        backtrack(new ArrayList<Integer>(), nums, used);
        return ans;
    }
    private void backtrack(List<Integer> path, int[] nums, boolean[] used) {
        if (path.size() == nums.length) {
            ans++;
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            if (!path.isEmpty()) {
                int s = path.get(path.size()-1) + nums[i];
                int r = (int)Math.sqrt(s);
                if (r*r != s) continue;
            }
            used[i] = true;
            path.add(nums[i]);
            backtrack(path, nums, used);
            path.remove(path.size()-1);
            used[i] = false;
        }
    }
}
