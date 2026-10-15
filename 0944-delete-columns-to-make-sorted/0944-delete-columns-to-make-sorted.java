class Solution {
    public int minDeletionSize(String[] strs) {
        if (strs == null || strs.length == 0) return 0;
        int rows = strs.length;
        int cols = strs[0].length();
        int ans = 0;
        for (int c = 0; c < cols; c++) {
            for (int r = 1; r < rows; r++) {
                if (strs[r].charAt(c) < strs[r-1].charAt(c)) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
}
