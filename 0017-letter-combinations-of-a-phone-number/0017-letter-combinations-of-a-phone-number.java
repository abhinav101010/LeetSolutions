import java.util.*;

class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();
        if (digits.length() == 0) {
            return ans;
        }

        String[] map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack(digits, 0, new StringBuilder(), map, ans);
        return ans;
    }

    private void backtrack(String digits, int i, StringBuilder sb, String[] map, List<String> ans) {
        if (i == digits.length()) {
            ans.add(sb.toString());
            return;
        }

        for (char c : map[digits.charAt(i) - '0'].toCharArray()) {
            sb.append(c);
            backtrack(digits, i + 1, sb, map, ans);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}
