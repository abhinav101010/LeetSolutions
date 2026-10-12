class Solution {
    public int sumOddLengthSubarrays(int[] arr) {
        int n = arr.length;
        int total = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j += 2) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += arr[k];
                }
                total += sum;
            }
        }

        return total;
    }
}
