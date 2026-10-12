class Solution {
    public boolean isSubsequence(String s, String t) {
        int prev = -1;
        for (int i = 0; i < s.length(); i++) {
            int curr = t.indexOf(s.charAt(i), prev + 1);
            if (curr == -1) {
                return false;
            }
            prev = curr;
        }
        return true;
    }
}