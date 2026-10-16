#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = 0, right = 0;
        for (int w : weights) {
            left = max(left, w);
            right += w;
        }
        while (left < right) {
            int mid = (left + right) / 2;
            int days = 1, cur = 0;
            for (int w : weights) {
                if (cur + w > mid) {
                    days++; cur = 0;
                }
                cur += w;
            }
            if (days <= D) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
