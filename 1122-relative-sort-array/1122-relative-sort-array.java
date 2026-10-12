import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        Map<Integer, Integer> count = new HashMap<>();

        for (int num : arr1) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }

        int[] ans = new int[arr1.length];
        int idx = 0;

        for (int num : arr2) {
            int c = count.get(num);
            for (int j = 0; j < c; j++) {
                ans[idx++] = num;
            }
            count.remove(num);
        }

        int[] remaining = new int[count.size()];
        int rIdx = 0;
        for (int num : count.keySet()) {
            remaining[rIdx++] = num;
        }
        java.util.Arrays.sort(remaining);

        for (int num : remaining) {
            int c = count.get(num);
            for (int j = 0; j < c; j++) {
                ans[idx++] = num;
            }
        }

        return ans;
    }
}