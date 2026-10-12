import java.util.*;

class Solution {
    private long count;
    
    public int countRangeSum(int[] nums, int lower, int upper) {
        int n = nums.length;
        long[] prefix = new long[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        count = 0;
        mergeSort(prefix, 0, n, lower, upper);
        return (int) count;
    }
    
    private long[] mergeSort(long[] arr, int left, int right, int lower, int upper) {
        if (right - left <= 1) return new long[]{arr[left]};
        
        int mid = left + (right - left) / 2;
        long[] leftArr = mergeSort(arr, left, mid, lower, upper);
        long[] rightArr = mergeSort(arr, mid, right, lower, upper);
        
        // Count valid pairs
        int j = 0, k = 0;
        for (long lVal : leftArr) {
            while (j < rightArr.length && rightArr[j] - lVal < lower) j++;
            while (k < rightArr.length && rightArr[k] - lVal <= upper) k++;
            count += k - j;
        }
        
        // Merge
        long[] merged = new long[leftArr.length + rightArr.length];
        int i = 0, p = 0, q = 0;
        while (p < leftArr.length || q < rightArr.length) {
            if (q == rightArr.length || (p < leftArr.length && leftArr[p] <= rightArr[q])) {
                merged[i++] = leftArr[p++];
            } else {
                merged[i++] = rightArr[q++];
            }
        }
        return merged;
    }
}