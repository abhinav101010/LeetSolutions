class Solution {
    public int findSubstringInWraproundString(String s) {
        int[] dp = new int[26];
        int maxLen = 0;
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (i > 0 && (ch - s.charAt(i-1) == 1 || (s.charAt(i-1) == 'z' && ch == 'a'))) {
                maxLen++;
            } else {
                maxLen = 1;
            }
            int idx = ch - 'a';
            dp[idx] = Math.max(dp[idx], maxLen);
        }
        
        int result = 0;
        for (int v : dp) result += v;
        return result;
    }
}