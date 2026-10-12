import java.util.*;

class Solution {
    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        Integer[] result = new Integer[n];
        Integer[][] enumArr = new Integer[n][2];
        for (int i = 0; i < n; i++) {
            enumArr[i][0] = i;
            enumArr[i][1] = nums[i];
        }
        
        mergeSort(enumArr, 0, n - 1, result);
        return Arrays.asList(result);
    }
    
    private Integer[][] mergeSort(Integer[][] arr, int left, int right, Integer[] result) {
        if (left >= right) return new Integer[][]{arr[left]};
        
        int mid = (left + right) / 2;
        Integer[][] leftArr = mergeSort(arr, left, mid, result);
        Integer[][] rightArr = mergeSort(arr, mid + 1, right, result);
        
        Integer[][] merged = new Integer[right - left + 1][2];
        int i = 0, j = 0, k = 0;
        while (i < leftArr.length || j < rightArr.length) {
            if (j == rightArr.length || (i < leftArr.length && leftArr[i][1] <= rightArr[j][1])) {
                result[leftArr[i][0]] += j;
                merged[k++] = leftArr[i++];
            } else {
                merged[k++] = rightArr[j++];
            }
        }
        return merged;
    }
}