class Solution {
    public int minDeletionSize(String[] strs) {
        int m = strs[0].length();
        int n = strs.length;
        boolean[] sorted = new boolean[n-1]; // sorted[i] = true if strs[i] < strs[i+1] already
        int ans = 0;
        for (int col = 0; col < m; col++) {
            boolean delete = false;
            for (int i = 0; i < n-1; i++) {
                if (!sorted[i] && strs[i].charAt(col) > strs[i+1].charAt(col)) {
                    delete = true;
                    break;
                }
            }
            if (delete) {
                ans++;
            } else {
                for (int i = 0; i < n-1; i++) {
                    if (!sorted[i] && strs[i].charAt(col) < strs[i+1].charAt(col)) {
                        sorted[i] = true;
                    }
                }
            }
        }
        return ans;
    }
}
