import java.util.*;
class Solution {
    public int threeSumMulti(int[] arr, int target) {
        final int MOD = 1000000007;
        int n = arr.length;
        long ans = 0;
        for (int i = 0; i < n; i++) {
            Map<Integer, Integer> memo = new HashMap<>();
            int rem = target - arr[i];
            for (int j = i + 1; j < n; j++) {
                int need = rem - arr[j];
                ans = (ans + memo.getOrDefault(need, 0)) % MOD;
                memo.put(arr[j], memo.getOrDefault(arr[j], 0) + 1);
            }
        }
        return (int) ans;
    }
}
