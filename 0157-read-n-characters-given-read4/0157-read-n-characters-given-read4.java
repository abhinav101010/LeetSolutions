/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char[] buf4);
 */
public class Solution extends Reader4 {
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    public int read(char[] buf, int n) {
        char[] buf4 = new char[4];
        int res = 0;
        while (res < n) {
            int count = read4(buf4);
            if (count == 0) break;
            for (int i = 0; i < count && res < n; i++) {
                buf[res++] = buf4[i];
            }
        }
        return res;
    }
}