class Solution {
    public int uniqueLetterString(String s) {
        int[][] pos = new int[26][];
        // first pass to count occurrences
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            pos[i] = new int[count[i] + 2]; // +2 for sentinels
            pos[i][0] = -1;
            pos[i][count[i]+1] = s.length();
        }
        // fill positions
        int[] idx = new int[26];
        for (int i = 0; i < s.length(); i++) {
            int c = s.charAt(i) - 'A';
            pos[c][idx[c]+1] = i;
            idx[c]++;
        }
        long ans = 0;
        for (int c = 0; c < 26; c++) {
            for (int i = 1; i < idx[c]+1; i++) {
                ans += (pos[c][i] - pos[c][i-1]) * (pos[c][i+1] - pos[c][i]);
            }
        }
        return (int) ans;
    }
}
