import java.util.*;

class Solution {
    public int[] sumAndMultiply(String s, int[][] queries) {
        int MOD = 1_000_000_007;
        int m = s.length();

        List<Integer> posList = new ArrayList<>();
        List<Integer> digits = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            char ch = s.charAt(i);
            if (ch != '0') {
                posList.add(i);
                digits.add(ch - '0');
            }
        }
        int n = digits.size();

        int[] prefixSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + digits.get(i);
        }

        long[] pow10 = new long[n + 1];
        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        long[] prefixVal = new long[n + 1];
        for (int i = 0; i < n; i++) {
            prefixVal[i + 1] = (prefixVal[i] * 10 + digits.get(i)) % MOD;
        }

        int[] pos = new int[n];
        for (int i = 0; i < n; i++) pos[i] = posList.get(i);

        int q = queries.length;
        int[] ans = new int[q];
        for (int qi = 0; qi < q; qi++) {
            int l = queries[qi][0], r = queries[qi][1];
            int left = lowerBound(pos, l);
            int right = upperBound(pos, r);
            if (left == right) {
                ans[qi] = 0;
                continue;
            }
            long digitSum = prefixSum[right] - prefixSum[left];
            long x = (prefixVal[right] - prefixVal[left] * pow10[right - left]) % MOD;
            if (x < 0) x += MOD;
            ans[qi] = (int)((x * digitSum) % MOD);
        }
        return ans;
    }

    private int lowerBound(int[] arr, int key) {
        int lo = 0, hi = arr.length;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] < key) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    private int upperBound(int[] arr, int key) {
        int lo = 0, hi = arr.length;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] <= key) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
}