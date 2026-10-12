class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        int[] dpLen = new int[n];
        int[] dpCnt = new int[n];
        Arrays.fill(dpLen, 1);
        Arrays.fill(dpCnt, 1);
        int maxLen = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dpLen[j] + 1 > dpLen[i]) {
                        dpLen[i] = dpLen[j] + 1;
                        dpCnt[i] = dpCnt[j];
                    } else if (dpLen[j] + 1 == dpLen[i]) {
                        dpCnt[i] += dpCnt[j];
                    }
                }
            }
            maxLen = Math.max(maxLen, dpLen[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (dpLen[i] == maxLen) res += dpCnt[i];
        }
        return res;
    }
}