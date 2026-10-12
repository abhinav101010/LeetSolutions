import java.util.*;

class Solution {
    public String[] findRelativeRanks(int[] score) {
        int n = score.length;
        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) indices[i] = i;
        
        Arrays.sort(indices, (a, b) -> score[b] - score[a]);
        
        String[] ans = new String[n];
        for (int i = 0; i < n; i++) {
            int idx = indices[i];
            if (i == 0) ans[idx] = "Gold Medal";
            else if (i == 1) ans[idx] = "Silver Medal";
            else if (i == 2) ans[idx] = "Bronze Medal";
            else ans[idx] = String.valueOf(i + 1);
        }
        return ans;
    }
}