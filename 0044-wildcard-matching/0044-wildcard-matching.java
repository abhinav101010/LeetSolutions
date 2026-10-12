class Solution {
    public boolean isMatch(String s, String p) {
        int si = 0;
        int pi = 0;
        int star = -1;
        int mark = 0;

        while (si < s.length()) {
            if (pi < p.length() && (p.charAt(pi) == '?' || p.charAt(pi) == s.charAt(si))) {
                si++;
                pi++;
            } else if (pi < p.length() && p.charAt(pi) == '*') {
                star = pi;
                mark = si;
                pi++;
            } else if (star != -1) {
                pi = star + 1;
                mark++;
                si = mark;
            } else {
                return false;
            }
        }

        while (pi < p.length() && p.charAt(pi) == '*') {
            pi++;
        }
        return pi == p.length();
    }
}
