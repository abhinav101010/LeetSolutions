import java.util.*;

class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {
        Set<List<Integer>> result = new HashSet<>();
        List<Integer> path = new ArrayList<>();
        backtrack(nums, 0, path, result);
        return new ArrayList<>(result);
    }
    
    private void backtrack(int[] nums, int start, List<Integer> path, Set<List<Integer>> result) {
        if (path.size() >= 2) {
            result.add(new ArrayList<>(path));
        }
        if (start >= nums.length) return;
        
        Set<Integer> used = new HashSet<>();
        for (int i = start; i < nums.length; i++) {
            if (used.contains(nums[i])) continue;
            if (path.isEmpty() || nums[i] >= path.get(path.size() - 1)) {
                used.add(nums[i]);
                path.add(nums[i]);
                backtrack(nums, i + 1, path, result);
                path.remove(path.size() - 1);
            }
        }
    }
}