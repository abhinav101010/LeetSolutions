#include <algorithm>
class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        int pos = 0;
        int cost = 0;
        while (target > 0) {
            int digit = target % x;
            target /= x;
            if (pos == 0) {
                cost = digit * 2;
            } else {
                cost = std::min(digit * pos + cost, (x - digit) * pos + cost);
            }
            pos++;
        }
        return cost - 1;
    }
};
