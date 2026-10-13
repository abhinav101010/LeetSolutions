import java.util.*;

class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    
    public List<List<Integer>> getFactors(int n) {
        dfs(2, new ArrayList<>(), n);
        return res;
    }
    
    private void dfs(int start, List<Integer> path, int remain) {
        if (remain == 1) {
            if (path.size() > 1) {
                res.add(new ArrayList<>(path));
            }
            return;
        }
        for (int i = start; i <= Math.sqrt(remain); i++) {
            if (remain % i == 0) {
                path.add(i);
                dfs(i, path, remain / i);
                path.remove(path.size() - 1);
            }
        }
        path.add(remain);
        dfs(remain, path, 1);
        path.remove(path.size() - 1);
    }
}