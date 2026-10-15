class Solution {
    public int longestMountain(int[] arr) {
        int n = arr.length;
        int ans = 0;
        int base = 0;
        while (base < n) {
            int end = base;
            // climb up
            if (end + 1 < n && arr[end] < arr[end + 1]) {
                while (end + 1 < n && arr[end] < arr[end + 1]) {
                    end++;
                }
                // peak?
                if (end + 1 < n && arr[end] > arr[end + 1]) {
                    while (end + 1 < n && arr[end] > arr[end + 1]) {
                        end++;
                    }
                    ans = Math.max(ans, end - base + 1);
                }
            }
            base = Math.max(end, base + 1);
        }
        return ans;
    }
}
