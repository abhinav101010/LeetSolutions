class Solution {
    public String licenseKeyFormatting(String s, int k) {
        StringBuilder ans = new StringBuilder();
        int temp = k;
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (c == '-') continue;
            if (temp == 0) {
                ans.append('-');
                temp = k;
            }
            ans.append(c);
            temp--;
        }
        return ans.reverse().toString().toUpperCase();
    }
}