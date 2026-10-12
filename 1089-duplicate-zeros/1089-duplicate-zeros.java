class Solution {
    public void duplicateZeros(int[] arr) {
        int[] ans = new int[arr.length];
        int idx = 0;

        for (int num : arr) {
            if (num == 0) {
                if (idx < ans.length) ans[idx++] = 0;
                if (idx < ans.length) ans[idx++] = 0;
            } else {
                if (idx < ans.length) ans[idx++] = num;
            }
        }

        System.arraycopy(ans, 0, arr, 0, arr.length);
    }
}