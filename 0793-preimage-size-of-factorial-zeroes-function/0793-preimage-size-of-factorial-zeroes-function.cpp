#include <vector>
using namespace std;

class Solution {
public:
    int preimageSizeFZF(int K) {
        long long lo = 0;
        long long hi = 5LL * K + 5; // safe upper bound
        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            if (trailingZeros(mid) < K) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return trailingZeros(lo) == K ? 5 : 0;
    }
private:
    long long trailingZeros(long long x) {
        long long count = 0;
        while (x > 0) {
            x /= 5;
            count += x;
        }
        return count;
    }
};
