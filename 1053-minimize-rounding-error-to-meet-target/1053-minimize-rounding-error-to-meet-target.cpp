#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
class Solution {
public:
    string minRoundingError(vector<string>& prices, int target) {
        vector<double> diff;
        long long low = 0, high = 0;
        for (auto &s:prices) {
            double f = stod(s);
            long long i = (long long)floor(f);
            low += i;
            if (fabs(f - i) < 1e-12) {
                high += i;
                diff.push_back(0.0);
            } else {
                high += i+1;
                diff.push_back(min(f-i, (i+1)-f));
            }
        }
        if (target < low || target > high) return "-1";
        long long need = target - low;
        sort(diff.begin(), diff.end());
        double res = 0;
        for (double d:diff) res += d;
        for (long long k=0;k<need;k++) {
            double d = diff[k];
            res = res - d + (1-d);
        }
        char buf[20];
        sprintf(buf, "%.3f", res);
        return string(buf);
    }
};
