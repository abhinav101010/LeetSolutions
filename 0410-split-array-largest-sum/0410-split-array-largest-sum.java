import java.util.*;

class Solution {
    public int splitArray(int[] nums, int k) {
        int left = 0, right = 0;
        for (int num : nums) {
            left = Math.max(left, num);
            right += num;
        }
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 1;
            int currSum = 0;
            for (int num : nums) {
                if (currSum + num > mid) {
                    count++;
                    currSum = num;
                } else {
                    currSum += num;
                }
            }
            if (count <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
}