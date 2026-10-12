import java.util.*;

class Solution {
    public int[] findRightInterval(int[][] intervals) {
        int n = intervals.length;
        int[][] startIdx = new int[n][2];
        for (int i = 0; i < n; i++) {
            startIdx[i][0] = intervals[i][0];
            startIdx[i][1] = i;
        }
        
        Arrays.sort(startIdx, (a, b) -> a[0] - b[0]);
        int[] starts = new int[n];
        for (int i = 0; i < n; i++) starts[i] = startIdx[i][0];
        
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            int idx = Arrays.binarySearch(starts, intervals[i][1]);
            if (idx < 0) idx = -(idx + 1);
            result[i] = idx < n ? startIdx[idx][1] : -1;
        }
        return result;
    }
}