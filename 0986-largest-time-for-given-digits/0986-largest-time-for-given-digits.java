import java.util.*;
class Solution {
    private String maxTime = "";
    public String largestTimeFromDigits(int[] arr) {
        maxTime = "";
        boolean[] used = new boolean[4];
        int[] perm = new int[4];
        dfs(arr, 0, used, perm);
        return maxTime;
    }
    private void dfs(int[] arr, int pos, boolean[] used, int[] perm) {
        if (pos == 4) {
            int hour = perm[0]*10 + perm[1];
            int minute = perm[2]*10 + perm[3];
            if (hour < 24 && minute < 60) {
                String t = String.format("%02d:%02d", hour, minute);
                if (t.compareTo(maxTime) > 0) {
                    maxTime = t;
                }
            }
            return;
        }
        for (int i = 0; i < 4; i++) {
            if (!used[i]) {
                used[i] = true;
                perm[pos] = arr[i];
                dfs(arr, pos+1, used, perm);
                used[i] = false;
            }
        }
    }
}
