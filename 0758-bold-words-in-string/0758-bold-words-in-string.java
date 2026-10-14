import java.util.*;

class Solution {
    public String boldWords(String[] words, String S) {
        boolean[] mark = new boolean[S.length()];
        for (String w : words) {
            int len = w.length();
            int pos = S.indexOf(w);
            while (pos != -1) {
                for (int i = pos; i < pos + len; i++) {
                    mark[i] = true;
                }
                pos = S.indexOf(w, pos + 1);
            }
        }
        StringBuilder sb = new StringBuilder();
        int i = 0;
        while (i < S.length()) {
            if (mark[i]) {
                sb.append("<b>");
                while (i < S.length() && mark[i]) {
                    sb.append(S.charAt(i));
                    i++;
                }
                sb.append("</b>");
            } else {
                sb.append(S.charAt(i));
                i++;
            }
        }
        return sb.toString();
    }
}
