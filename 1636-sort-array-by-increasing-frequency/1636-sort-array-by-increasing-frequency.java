import java.util.Arrays;

class Solution {
    public int[] frequencySort(int[] nums) {
        int[] freq = new int[201];

        for (int num : nums) {
            freq[num + 100]++;
        }

        Integer[] boxed = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) {
            boxed[i] = nums[i];
        }

        Arrays.sort(boxed, (a, b) -> {
            if (freq[a + 100] != freq[b + 100]) {
                return freq[a + 100] - freq[b + 100];
            }
            return b - a;
        });

        int[] result = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            result[i] = boxed[i];
        }

        return result;
    }
}