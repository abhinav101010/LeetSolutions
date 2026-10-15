class Solution {
    public int minFlipsMonoIncr(String s) {
        int ones = 0;
        int ans = 0;
        for (char ch : s.toCharArray()) {
            if (ch == '1') {
                ones++;
            } else {
                ans = Math.min(ans + 1, ones);
            }
        }
        return ans;
    }
}
