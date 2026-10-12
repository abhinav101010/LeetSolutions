class Solution {
    public int findSpecialInteger(int[] arr) {
        int count = 1;
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            if (count > n / 4) {
                return arr[i];
            }
        }
        return arr[0];
    }
}