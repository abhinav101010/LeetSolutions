class Solution {
    public String replaceDigits(String s) {
        char[] result = s.toCharArray();
        for (int i = 1; i < s.length(); i += 2) {
            result[i] = (char) (s.charAt(i - 1) + (s.charAt(i) - '0'));
        }
        return new String(result);
    }
}