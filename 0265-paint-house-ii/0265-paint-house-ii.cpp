#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) {
            return 0;
        }
        int n = costs.size();
        int k = costs[0].size();
        vector<int> prev = costs[0];
        for (int i = 1; i < n; i++) {
            vector<int> curr(k, 0);
            int min1 = INT_MAX;
            int min2 = INT_MAX;
            int idx = -1;
            for (int j = 0; j < k; j++) {
                if (prev[j] < min1) {
                    min2 = min1;
                    min1 = prev[j];
                    idx = j;
                } else if (prev[j] < min2) {
                    min2 = prev[j];
                }
            }
            for (int j = 0; j < k; j++) {
                if (j == idx) {
                    curr[j] = min2 + costs[i][j];
                } else {
                    curr[j] = min1 + costs[i][j];
                }
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};
