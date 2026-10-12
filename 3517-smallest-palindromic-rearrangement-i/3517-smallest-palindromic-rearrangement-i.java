class Solution {
    public String smallestPalindrome(String s) {
        int[] count = new int[26];
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;
        }
        StringBuilder half = new StringBuilder();
        char middle = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            int idx = c - 'a';
            for (int i = 0; i < count[idx] / 2; i++) {
                half.append(c);
            }
            if (count[idx] % 2 == 1) {
                middle = c;
            }
        }
        String rev = half.reverse().toString();
        half.reverse();
        return half.toString() + (middle == 0 ? "" : String.valueOf(middle)) + rev;
    }
}