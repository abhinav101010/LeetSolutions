import java.util.*;

class Solution {
    public void wiggleSort(int[] nums) {
        int n = nums.length;
        if (n <= 1) return;
        
        // Find median using quickselect
        int median = quickselect(nums.clone(), n / 2);
        
        // 3-way partition with virtual indexing
        int left = 0, i = 0, right = n - 1;
        while (i <= right) {
            int virtualI = (1 + 2 * i) % (n | 1);
            if (nums[virtualI] > median) {
                int virtualLeft = (1 + 2 * left) % (n | 1);
                swap(nums, virtualLeft, virtualI);
                left++;
                i++;
            } else if (nums[virtualI] < median) {
                int virtualRight = (1 + 2 * right) % (n | 1);
                swap(nums, virtualRight, virtualI);
                right--;
            } else {
                i++;
            }
        }
    }
    
    private int quickselect(int[] arr, int k) {
        int left = 0, right = arr.length - 1;
        while (left <= right) {
            int pivotIdx = left + (right - left) / 2;
            int pivot = arr[pivotIdx];
            int l = left, r = right;
            while (l <= r) {
                while (arr[l] < pivot) l++;
                while (arr[r] > pivot) r--;
                if (l <= r) {
                    swap(arr, l, r);
                    l++;
                    r--;
                }
            }
            if (k <= r) right = r;
            else if (k >= l) left = l;
            else return pivot;
        }
        return arr[k];
    }
    
    private void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}