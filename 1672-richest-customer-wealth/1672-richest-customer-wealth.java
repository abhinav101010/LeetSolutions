class Solution {
    public int maximumWealth(int[][] accounts) {
        int ans = 0;
        for (int i = 0; i < accounts.length; i++) {
            int accSum = 0;
            for (int j = 0; j < accounts[i].length; j++) {
                accSum+=accounts[i][j];
            }
            ans = Integer.max(ans, accSum);
        }
        return ans;
    }
}