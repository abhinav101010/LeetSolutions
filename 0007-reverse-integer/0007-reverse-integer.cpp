class Solution {
public:
    int reverse(int x) {
        int sign = x < 0 ? -1 : 1;
        long rest = x < 0 ? -(long)x : x;
        long ans = 0;

        while (rest > 0) {
            ans = ans * 10 + rest % 10;
            rest /= 10;

            if (ans > INT_MAX) return 0;
        }

        return sign * (int)ans;
    }
};
