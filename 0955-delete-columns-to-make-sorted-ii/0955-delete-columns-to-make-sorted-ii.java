class Solution {
    public int minDeletionSize(String[] strs) {
        int n = strs.length;
        int m = strs[0].length();
        boolean[] sorted = new boolean[n-1];
        int ans = 0;
        for (int col = 0; col < m; col++) {
            boolean ok = true;
            for (int i = 0; i < n-1; i++) {
                if (!sorted[i] && strs[i].charAt(col) > strs[i+1].charAt(col)) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                ans++;
                continue;
            }
            for (int i = 0; i < n-1; i++) {
                if (!sorted[i] && strs[i].charAt(col) < strs[i+1].charAt(col)) {
                    sorted[i] = true;
                }
            }
        }
        return ans;
    }
}
