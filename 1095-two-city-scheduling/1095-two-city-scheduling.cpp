#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](auto& a, auto& b){ return (a[0]-a[1]) < (b[0]-b[1]); });
        int n = costs.size() / 2, ans = 0;
        for (int i = 0; i < n; i++) ans += costs[i][0];
        for (int i = n; i < (int)costs.size(); i++) ans += costs[i][1];
        return ans;
    }
};
