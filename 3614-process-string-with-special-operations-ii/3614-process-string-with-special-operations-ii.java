class Solution {
    public String processStr(String s, long k) {
        long length = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '*') {
                if (length > 0) length--;
            } else if (c == '#') {
                length *= 2;
            } else if (c == '%') {
                // no length change
            } else {
                length++;
            }
        }
        if (k >= length) return ".";

        StringBuilder sb = new StringBuilder();
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (c == '#') {
                length /= 2;
                k %= length;
            } else if (c == '%') {
                k = length - 1 - k;
            } else if (c == '*') {
                length++;
            } else {
                length--;
                if (k == length) return String.valueOf(c);
            }
        }
        return ".";
    }
}