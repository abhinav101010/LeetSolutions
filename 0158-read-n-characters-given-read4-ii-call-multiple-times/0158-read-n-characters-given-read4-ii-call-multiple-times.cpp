class Solution {
public:
    int buf4[4];
    int i4 = 0, n4 = 0;
    int read(char *buf, int n) {
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
};