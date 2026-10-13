class Solution {
public:
    int read(char *buf, int n) {
        char buf4[4];
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
};