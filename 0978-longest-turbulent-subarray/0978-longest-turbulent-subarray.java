class Solution {
    public int maxTurbulenceSize(int[] arr) {
        int n = arr.length;
        if (n < 2) return n;
        int ans = 1;
        int up = 1, down = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i-1]) {
                up = down + 1;
                down = 1;
            } else if (arr[i] < arr[i-1]) {
                down = up + 1;
                up = 1;
            } else {
                up = down = 1;
            }
            ans = Math.max(ans, Math.max(up, down));
        }
        return ans;
    }
}
