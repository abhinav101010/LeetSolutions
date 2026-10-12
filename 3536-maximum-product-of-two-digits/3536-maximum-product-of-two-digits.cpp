class Solution {
public:
    int maxProduct(int n) {
        int cnt[10] = {0};
        int x = n;
        while (x > 0) {
            cnt[x % 10]++;
            x /= 10;
        }
        int max1 = -1, max2 = -1;
        int min1 = 10, min2 = 10;
        for (int d = 9; d >= 0; d--) {
            while (cnt[d]-- > 0) {
                if (max1 == -1) max1 = d;
                else if (max2 == -1) max2 = d;
            }
        }
        for (int d = 0; d <= 9; d++) {
            cnt[d] = 0;
        }
        x = n;
        while (x > 0) {
            cnt[x % 10]++;
            x /= 10;
        }
        for (int d = 0; d <= 9; d++) {
            while (cnt[d]-- > 0) {
                if (min1 == 10) min1 = d;
                else if (min2 == 10) min2 = d;
            }
        }
        return std::max(max1 * max2, min1 * min2);
    }
};