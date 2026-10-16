import java.util.*;
class StringIterator {
    private String s;
    private int i = 0, cnt = 0;
    private char ch;
    public StringIterator(String compressedString) {
        s = compressedString;
        i = 0; cnt = 0; ch = ' ';
    }
    public char next() {
        if (hasNext()) {
            cnt--;
            return ch;
        }
        return ' ';
    }
    public boolean hasNext() {
        if (cnt > 0) return true;
        if (i >= s.length()) return false;
        ch = s.charAt(i++);
        int j = i;
        while (j < s.length() && Character.isDigit(s.charAt(j))) {
            j++;
        }
        cnt = Integer.parseInt(s.substring(i, j));
        i = j;
        return true;
    }
}
