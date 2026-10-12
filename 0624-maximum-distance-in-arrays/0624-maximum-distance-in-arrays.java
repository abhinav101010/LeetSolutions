import java.util.*;

class Solution {
    public int maxDistance(int[][] arrays) {
        int res = 0;
        int minVal = arrays[0][0];
        int maxVal = arrays[0][arrays[0].length - 1];
        
        for (int i = 1; i < arrays.length; i++) {
            int[] arr = arrays[i];
            res = Math.max(res, Math.max(Math.abs(arr[arr.length - 1] - minVal), Math.abs(maxVal - arr[0])));
            minVal = Math.min(minVal, arr[0]);
            maxVal = Math.max(maxVal, arr[arr.length - 1]);
        }
        
        return res;
    }
}