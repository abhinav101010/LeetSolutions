class Solution {
    public int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int num = num1; num <= num2; num++) {
            char[] arr = Integer.toString(num).toCharArray();
            for (int i = 1; i < arr.length - 1; i++) {
                if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) ans++;
                if (arr[i - 1] > arr[i] && arr[i] < arr[i + 1]) ans++;
            }
        }
        return ans;
    }
}