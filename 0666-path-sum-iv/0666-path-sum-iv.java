import java.util.*;

class Solution {
    public int pathSum(List<Integer> nums) {
        if (nums == null || nums.isEmpty()) return 0;
        Map<Integer, Map<Integer, Integer>> val = new HashMap<>();
        for (int num : nums) {
            int d = num / 100;
            int p = (num % 100) / 10;
            int v = num % 10;
            val.computeIfAbsent(d, k -> new HashMap<>()).put(p, v);
        }
        return dfs(1, 1, 0, val);
    }
    
    private int dfs(int d, int p, int curSum, Map<Integer, Map<Integer, Integer>> val) {
        Map<Integer, Integer> row = val.get(d);
        if (row == null || !row.containsKey(p)) {
            return 0;
        }
        curSum += row.get(p);
        int leftP = p*2-1;
        int rightP = p*2;
        boolean leftExists = val.containsKey(d+1) && val.get(d+1).containsKey(leftP);
        boolean rightExists = val.containsKey(d+1) && val.get(d+1).containsKey(rightP);
        if (!leftExists && !rightExists) {
            return curSum;
        }
        int sum = 0;
        if (leftExists) {
            sum += dfs(d+1, leftP, curSum, val);
        }
        if (rightExists) {
            sum += dfs(d+1, rightP, curSum, val);
        }
        return sum;
    }
}
