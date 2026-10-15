import java.util.*;

class Solution {
    public String addBoldTag(String s, String[] dict) {
        boolean[] bold = new boolean[s.length()];
        for (String word : dict) {
            int start = s.indexOf(word);
            while (start != -1) {
                for (int i = start; i < Math.min(start + word.length(), s.length()); i++) {
                    bold[i] = true;
                }
                start = s.indexOf(word, start + 1);
            }
        }
        StringBuilder res = new StringBuilder();
        int i = 0;
        while (i < s.length()) {
            if (bold[i]) {
                res.append("<b>");
                while (i < s.length() && bold[i]) {
                    res.append(s.charAt(i));
                    i++;
                }
                res.append("</b>");
            } else {
                res.append(s.charAt(i));
                i++;
            }
        }
        return res.toString();
    }
}
