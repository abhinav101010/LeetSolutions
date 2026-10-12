class Solution {
public:
    int sumAndMultiply(int n) {
        if (n == 0) return 0;
        string str = to_string(n);
        int s = 0;
        int x = 0;
        for (char c : str) {
            if (c != '0') {
                s += c - '0';
                x = x * 10 + (c - '0');
            }
        }
        return x * s;
    }
};