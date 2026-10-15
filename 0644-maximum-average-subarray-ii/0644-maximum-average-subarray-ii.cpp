#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double lo = *min_element(nums.begin(), nums.end());
        double hi = *max_element(nums.begin(), nums.end());
        double eps = 1e-5;
        auto check = [&](double avg) -> bool {
            int n = nums.size();
            vector<double> prefix(n+1, 0.0);
            for (int i = 0; i < n; i++) {
                prefix[i+1] = prefix[i] + nums[i] - avg;
            }
            double minPrefix = 0.0;
            for (int i = k; i <= n; i++) {
                if (prefix[i] - minPrefix >= 0) {
                    return true;
                }
                if (prefix[i-k+1] < minPrefix) {
                    minPrefix = prefix[i-k+1];
                }
            }
            return false;
        };
        while (hi - lo > eps) {
            double mid = (lo + hi) / 2.0;
            if (check(mid)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
