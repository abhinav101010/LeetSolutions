public class Solution extends Reader4 {
    private char[] buf4 = new char[4];
    private int i4 = 0;
    private int n4 = 0;
    
    public int read(char[] buf, int n) {
        int res = 0;
        while (res < n) {
            if (i4 < n4) {
                buf[res++] = buf4[i4++];
            } else {
                n4 = read4(buf4);
                i4 = 0;
                if (n4 == 0) break;
            }
        }
        return res;
    }
}