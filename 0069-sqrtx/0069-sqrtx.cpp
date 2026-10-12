class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }

        long long left = 2;
        long long right = x / 2;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (mid * mid <= x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return (int)(left - 1);
    }
};
