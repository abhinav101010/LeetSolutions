import java.util.*;

class Solution {
    private char[][] pairs = {{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
    
    public int strobogrammaticInRange(String low, String high) {
        int res = 0;
        for (int n = low.length(); n <= high.length(); n++) {
            List<String> list = find(n);
            for (String s : list) {
                if (n == low.length() && s.length() == low.length() && s.compareTo(low) < 0) continue;
                if (n == high.length() && s.length() == high.length() && s.compareTo(high) > 0) continue;
                res++;
            }
        }
        return res;
    }
    
    private List<String> find(int n) {
        List<String> res = new ArrayList<>();
        char[] s = new char[n];
        dfs(0, n - 1, s, res);
        return res;
    }
    
    private void dfs(int left, int right, char[] s, List<String> res) {
        if (left > right) {
            res.add(new String(s));
            return;
        }
        for (char[] p : pairs) {
            if (left == 0 && right == s.length - 1 && p[0] == '0' && s.length > 1) continue;
            if (left == right && p[0] != p[1]) continue;
            s[left] = p[0];
            s[right] = p[1];
            dfs(left + 1, right - 1, s, res);
        }
    }
}