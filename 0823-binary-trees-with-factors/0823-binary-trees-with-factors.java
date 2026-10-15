import java.util.*;
class Solution {
    public int numFactoredBinaryTrees(int[] arr) {
        final int MOD = 1000000007;
        Arrays.sort(arr);
        Map<Integer, Long> dp = new HashMap<>();
        for (int x : arr) {
            dp.put(x, 1L);
        }
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    int right = arr[i] / arr[j];
                    if (dp.containsKey(right)) {
                        long val = (dp.get(arr[i]) + dp.get(arr[j]) * dp.get(right)) % MOD;
                        dp.put(arr[i], val);
                    }
                }
            }
        }
        long ans = 0;
        for (long v : dp.values()) {
            ans = (ans + v) % MOD;
        }
        return (int) ans;
    }
}
