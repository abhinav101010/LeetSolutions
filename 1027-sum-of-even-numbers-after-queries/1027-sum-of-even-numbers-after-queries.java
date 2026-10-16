class Solution {
    public int[] sumEvenAfterQueries(int[] nums, int[][] queries) {
        long S = 0;
        for (int x : nums) if (x % 2 == 0) S += x;
        int[] res = new int[queries.length];
        for (int k = 0; k < queries.length; k++) {
            int val = queries[k][0], idx = queries[k][1];
            if (nums[idx] % 2 == 0) S -= nums[idx];
            nums[idx] += val;
            if (nums[idx] % 2 == 0) S += nums[idx];
            res[k] = (int)S;
        }
        return res;
    }
}
