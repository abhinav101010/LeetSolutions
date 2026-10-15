#include <vector>
using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> cntN = digitCount(n);
        for (int i = 0; i < 31; i++) {
            int p = 1 << i;
            if (digitCount(p) == cntN) {
                return true;
            }
        }
        return false;
    }
private:
    vector<int> digitCount(int x) {
        vector<int> cnt(10, 0);
        while (x) {
            cnt[x % 10]++;
            x /= 10;
        }
        return cnt;
    }
};
