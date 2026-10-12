import java.util.*;

class Solution {
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        Map<Integer, Integer> sum12 = new HashMap<>();
        for (int a : nums1) {
            for (int b : nums2) {
                int sum = a + b;
                sum12.put(sum, sum12.getOrDefault(sum, 0) + 1);
            }
        }
        
        int count = 0;
        for (int c : nums3) {
            for (int d : nums4) {
                count += sum12.getOrDefault(-(c + d), 0);
            }
        }
        return count;
    }
}