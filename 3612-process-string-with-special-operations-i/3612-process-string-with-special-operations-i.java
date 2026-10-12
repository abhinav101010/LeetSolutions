class Solution {
    public String processStr(String s) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '*') {
                if (ans.length() > 0) ans.deleteCharAt(ans.length() - 1);
            } else if (c == '#') {
                int len = ans.length();
                for (int j = 0; j < len; j++) ans.append(ans.charAt(j));
            } else if (c == '%') {
                ans.reverse();
            } else {
                ans.append(c);
            }
        }
        return ans.toString();
    }
}