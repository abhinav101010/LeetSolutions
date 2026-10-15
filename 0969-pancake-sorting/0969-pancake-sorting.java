import java.util.*;
class Solution {
    public List<Integer> pancakeSort(int[] arr) {
        List<Integer> res = new ArrayList<>();
        int n = arr.length;
        for (int target = n; target > 1; target--) {
            int idx = -1;
            for (int i = 0; i < n; i++) {
                if (arr[i] == target) {
                    idx = i;
                    break;
                }
            }
            if (idx == target - 1) continue;
            if (idx != 0) {
                reverse(arr, 0, idx);
                res.add(idx+1);
            }
            reverse(arr, 0, target-1);
            res.add(target);
        }
        return res;
    }
    private void reverse(int[] arr, int left, int right) {
        while (left < right) {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }
    }
}
