import java.util.*;

class Solution {
    private List<String> res = new ArrayList<>();
    private char[][] pairs = {{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
    
    public List<String> findStrobogrammatic(int n) {
        char[] s = new char[n];
        dfs(0, n - 1, s);
        return res;
    }
    
    private void dfs(int left, int right, char[] s) {
        if (left > right) {
            res.add(new String(s));
            return;
        }
        for (char[] p : pairs) {
            if (left == 0 && right == s.length - 1 && p[0] == '0' && s.length > 1) continue;
            if (left == right && p[0] != p[1]) continue;
            s[left] = p[0];
            s[right] = p[1];
            dfs(left + 1, right - 1, s);
        }
    }
}