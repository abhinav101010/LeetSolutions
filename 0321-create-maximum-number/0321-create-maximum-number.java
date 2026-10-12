import java.util.*;

class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int[] best = new int[k];
        for (int i = Math.max(0, k - nums2.length); i <= Math.min(k, nums1.length); i++) {
            int[] candidate = merge(maxSubsequence(nums1, i), maxSubsequence(nums2, k - i));
            if (compare(candidate, 0, best, 0) > 0) {
                best = candidate;
            }
        }
        return best;
    }
    
    private int[] maxSubsequence(int[] nums, int k) {
        int drop = nums.length - k;
        int[] stack = new int[k];
        int top = -1;
        for (int num : nums) {
            while (top >= 0 && drop > 0 && stack[top] < num) {
                top--;
                drop--;
            }
            if (top + 1 < k) {
                stack[++top] = num;
            } else {
                drop--;
            }
        }
        return stack;
    }
    
    private int[] merge(int[] a, int[] b) {
        int[] result = new int[a.length + b.length];
        int i = 0, j = 0, k = 0;
        while (i < a.length || j < b.length) {
            if (compare(a, i, b, j) > 0) {
                result[k++] = a[i++];
            } else {
                result[k++] = b[j++];
            }
        }
        return result;
    }
    
    private int compare(int[] a, int i, int[] b, int j) {
        while (i < a.length && j < b.length && a[i] == b[j]) {
            i++;
            j++;
        }
        if (j == b.length) return 1;
        if (i == a.length) return -1;
        return a[i] - b[j];
    }
}