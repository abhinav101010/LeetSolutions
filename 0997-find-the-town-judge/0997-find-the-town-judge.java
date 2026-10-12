class Solution {
    public int findJudge(int n, int[][] trust) {
        int[] trusts = new int[n + 1];
        int[] trustedBy = new int[n + 1];
        for (int[] t : trust) {
            trusts[t[0]]++;
            trustedBy[t[1]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (trusts[i] == 0 && trustedBy[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
}
