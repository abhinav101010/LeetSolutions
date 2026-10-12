class Solution {
    public int countBinarySubstrings(String s) {
        int[] groups = new int[s.length()];
        int g = 0;
        groups[0] = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i - 1) != s.charAt(i)) {
                groups[++g] = 1;
            } else {
                groups[g]++;
            }
        }

        int ans = 0;
        for (int i = 1; i <= g; i++) {
            ans += Math.min(groups[i - 1], groups[i]);
        }
        return ans;
    }
}