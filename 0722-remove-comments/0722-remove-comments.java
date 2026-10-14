import java.util.*;

class Solution {
    public List<String> removeComments(List<String> source) {
        boolean inBlock = false;
        List<String> ans = new ArrayList<>();
        for (String line : source) {
            int i = 0;
            StringBuilder cur = new StringBuilder();
            while (i < line.length()) {
                if (!inBlock && i + 1 < line.length() && line.charAt(i) == '/' && line.charAt(i+1) == '*') {
                    inBlock = true;
                    i += 2;
                } else if (!inBlock && i + 1 < line.length() && line.charAt(i) == '/' && line.charAt(i+1) == '/') {
                    break;
                } else if (inBlock && i + 1 < line.length() && line.charAt(i) == '*' && line.charAt(i+1) == '/') {
                    inBlock = false;
                    i += 2;
                } else if (!inBlock) {
                    cur.append(line.charAt(i));
                    i++;
                } else {
                    i++;
                }
            }
            if (!inBlock && cur.length() > 0) {
                ans.add(cur.toString());
            }
        }
        return ans;
    }
}
