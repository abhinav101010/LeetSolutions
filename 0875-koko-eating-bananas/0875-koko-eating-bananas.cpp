#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canEat(piles, h, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
private:
    bool canEat(vector<int>& piles, int h, int speed) {
        long long hours = 0;
        for (int p : piles) {
            hours += (long long)(p + speed - 1) / speed;
            if (hours > h) return false;
        }
        return hours <= h;
    }
};
