import java.util.*;

class Solution {
    private String res;
    private int n;
    private List<String> dictList;
    
    public String minAbbreviation(String target, String[] dictionary) {
        this.n = target.length();
        this.res = target;
        dictList = new ArrayList<>();
        for (String d : dictionary) {
            if (d.length() == n) dictList.add(d);
        }
        backtrack(target, 0, 0, new StringBuilder());
        return res;
    }
    
    private boolean isMatch(String abbr, String word) {
        int i = 0, j = 0;
        while (i < abbr.length() && j < word.length()) {
            char c = abbr.charAt(i);
            if (Character.isDigit(c)) {
                if (c == '0') return false;
                int k = i;
                while (k < abbr.length() && Character.isDigit(abbr.charAt(k))) k++;
                int num = Integer.parseInt(abbr.substring(i, k));
                j += num;
                i = k;
            } else if (abbr.charAt(i) == word.charAt(j)) {
                i++; j++;
            } else {
                return false;
            }
        }
        return i == abbr.length() && j == word.length();
    }
    
    private void backtrack(String target, int pos, int count, StringBuilder cur) {
        if (pos == n) {
            if (count > 0) cur.append(count);
            String cand = cur.toString();
            boolean match = false;
            for (String d : dictList) {
                if (isMatch(cand, d)) {
                    match = true;
                    break;
                }
            }
            if (!match) {
                if (cand.length() < res.length() || (cand.length() == res.length() && cand.compareTo(res) < 0)) {
                    res = cand;
                }
            }
            if (count > 0) cur.setLength(cur.length() - String.valueOf(count).length());
            return;
        }
        if (count > 0) {
            backtrack(target, pos + 1, count + 1, cur);
            int lenCount = String.valueOf(count).length();
            cur.append(count).append(target.charAt(pos));
            backtrack(target, pos + 1, 0, cur);
            cur.setLength(cur.length() - 1 - lenCount);
        } else {
            cur.append(target.charAt(pos));
            backtrack(target, pos + 1, 0, cur);
            cur.setLength(cur.length() - 1);
            backtrack(target, pos + 1, 1, cur);
        }
    }
}