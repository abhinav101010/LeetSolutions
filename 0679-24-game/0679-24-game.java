import java.util.*;

class Solution {
    public boolean judgePoint24(int[] cards) {
        List<Double> nums = new ArrayList<>();
        for (int c : cards) nums.add((double)c);
        return dfs(nums);
    }
    
    private boolean dfs(List<Double> nums) {
        if (nums.size() == 1) return Math.abs(nums.get(0) - 24) < 1e-6;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                List<Double> nextNums = new ArrayList<>();
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) nextNums.add(nums.get(k));
                }
                char[] ops = {'+', '-', '*', '/'};
                for (char op : ops) {
                    if ((op == '+' || op == '*') && j > i) continue;
                    if (op == '/' && Math.abs(nums.get(j)) < 1e-6) continue;
                    double res = 0;
                    if (op == '+') res = nums.get(i) + nums.get(j);
                    else if (op == '-') res = nums.get(i) - nums.get(j);
                    else if (op == '*') res = nums.get(i) * nums.get(j);
                    else if (op == '/') res = nums.get(i) / nums.get(j);
                    nextNums.add(res);
                    if (dfs(nextNums)) return true;
                    nextNums.remove(nextNums.size() - 1);
                }
            }
        }
        return false;
    }
}