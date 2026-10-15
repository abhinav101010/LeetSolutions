#include <climits>
class Solution {
public:
    int smallestFactorization(int a) {
        if (a < 2) return a;
        int count[10] = {0}; // index 2-9
        for (int d = 9; d >= 2; d--) {
            while (a % d == 0) {
                a /= d;
                count[d]++;
            }
        }
        if (a > 1) return 0;
        long res = 0;
        for (int d = 2; d <= 9; d++) {
            for (int i = 0; i < count[d]; i++) {
                res = res * 10 + d;
                if (res > INT_MAX) return 0;
            }
        }
        return (int) res;
    }
};
