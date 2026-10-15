import java.util.*;

class Solution {
    public List<String> letterCasePermutation(String s) {
        List<String> res = new ArrayList<>();
        dfs(0, new StringBuilder(), s, res);
        return res;
    }
    private void dfs(int i, StringBuilder cur, String s, List<String> res) {
        if (i == s.length()) {
            res.add(cur.toString());
            return;
        }
        char c = s.charAt(i);
        if (Character.isLetter(c)) {
            cur.append(Character.toLowerCase(c));
            dfs(i+1, cur, s, res);
            cur.deleteCharAt(cur.length()-1);
            cur.append(Character.toUpperCase(c));
            dfs(i+1, cur, s, res);
            cur.deleteCharAt(cur.length()-1);
        } else {
            cur.append(c);
            dfs(i+1, cur, s, res);
            cur.deleteCharAt(cur.length()-1);
        }
    }
}
