import java.util.*;

class Solution {
    public List<String> generateAbbreviations(String word) {
        List<String> res = new ArrayList<>();
        backtrack(word, 0, 0, new StringBuilder(), res);
        return res;
    }
    
    private void backtrack(String word, int pos, int count, StringBuilder cur, List<String> res) {
        if (pos == word.length()) {
            if (count > 0) cur.append(count);
            res.add(cur.toString());
            if (count > 0) cur.setLength(cur.length() - String.valueOf(count).length());
            return;
        }
        cur.append(word.charAt(pos));
        backtrack(word, pos + 1, 0, cur, res);
        cur.setLength(cur.length() - 1);
        if (count == 0 || cur.length() == 0 || Character.isLetter(cur.charAt(cur.length() - 1))) {
            // count branch
        }
        backtrack(word, pos + 1, count + 1, cur, res);
        if (count > 0) {
            cur.append(count).append(word.charAt(pos));
            backtrack(word, pos + 1, 0, cur, res);
            cur.setLength(cur.length() - 1 - String.valueOf(count).length());
        }
    }
}