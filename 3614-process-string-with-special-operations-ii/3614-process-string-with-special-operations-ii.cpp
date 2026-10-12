class Solution {
public:
    string processStr(string s, long long k) {
        long long length = 0;
        for (char c : s) {
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

        string result;
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if (c == '#') {
                length /= 2;
                k %= length;
            } else if (c == '%') {
                k = length - 1 - k;
            } else if (c == '*') {
                length++;
            } else {
                length--;
                if (k == length) return string(1, c);
            }
        }
        return ".";
    }
};