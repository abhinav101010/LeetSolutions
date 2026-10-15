class Solution {
    public boolean canTransform(String start, String end) {
        int n = start.length();
        int i = 0, j = 0;
        while (i < n || j < n) {
            while (i < n && start.charAt(i) == 'X') i++;
            while (j < n && end.charAt(j) == 'X') j++;
            if (i == n && j == n) break;
            if (i == n || j == n) return false;
            if (start.charAt(i) != end.charAt(j)) return false;
            if (start.charAt(i) == 'L') {
                if (i < j) return false;
            } else { // 'R'
                if (i > j) return false;
            }
            i++;
            j++;
        }
        return true;
    }
}
