import java.util.*;

class Solution {
    public String crackSafe(int n, int k) {
        if (n == 1) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < k; i++) sb.append(i);
            return sb.toString();
        }
        Set<String> visited = new HashSet<>();
        List<Integer> ans = new ArrayList<>();
        String start = "";
        for (int i = 0; i < n-1; i++) start += '0';
        dfs(start, visited, ans, k);
        StringBuilder sb = new StringBuilder(start);
        for (int i = ans.size() - 1; i >= 0; i--) {
            sb.append(ans.get(i));
        }
        return sb.toString();
    }
    
    private void dfs(String node, Set<String> visited, List<Integer> ans, int k) {
        for (int x = 0; x < k; x++) {
            String edge = node + x;
            if (!visited.contains(edge)) {
                visited.add(edge);
                dfs(edge.substring(1), visited, ans, k); // next node is suffix of length n-1
                ans.add(x);
            }
        }
    }
}
