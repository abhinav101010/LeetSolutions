#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double lo = 0.0;
        double hi = stations.back() - stations.front();
        for (int iter = 0; iter < 100; iter++) {
            double mid = (lo + hi) / 2.0;
            if (possible(stations, k, mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    }
    
    bool possible(vector<int>& stations, int k, double D) {
        int count = 0;
        for (int i = 1; i < stations.size(); i++) {
            double gap = stations[i] - stations[i-1];
            int needed = (int)ceil(gap / D) - 1;
            count += needed;
            if (count > k) return false;
        }
        return count <= k;
    }
};
