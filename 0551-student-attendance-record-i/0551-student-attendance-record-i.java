class Solution {
    public boolean checkRecord(String s) {
        int late = 0;
        int absent = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == 'A') {
                absent++;
                if (absent > 1) {
                    return false;
                }
            }
            if (c == 'L') {
                late++;
                if (late >= 3) {
                    return false;
                }
                continue;
            }
            late = 0;
        }
        return true;
    }
}