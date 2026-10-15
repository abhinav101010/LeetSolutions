class Solution {
    public String decodeAtIndex(String s, int k) {
        long length = 0;
        for (char ch : s.toCharArray()) {
            if (Character.isDigit(ch)) {
                length *= (ch - '0');
            } else {
                length++;
            }
        }
        for (int i = s.length() - 1; i >= 0; i--) {
            char ch = s.charAt(i);
            if (k % length == 0 && Character.isLetter(ch)) {
                return String.valueOf(ch);
            }
            if (Character.isDigit(ch)) {
                length /= (ch - '0');
            } else {
                length--;
            }
        }
        return "";
    }
}
