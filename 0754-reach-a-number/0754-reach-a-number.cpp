#include <cstdlib>
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int k = 0;
        int total = 0;
        while (total < target || ((total - target) & 1) != 0) {
            k++;
            total += k;
        }
        return k;
    }
};
