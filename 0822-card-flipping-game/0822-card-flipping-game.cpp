#include <vector>
#include <unordered_set>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> same;
        for (int i = 0; i < fronts.size(); i++) {
            if (fronts[i] == backs[i]) {
                same.insert(fronts[i]);
            }
        }
        int ans = INT_MAX;
        for (int f : fronts) {
            if (same.find(f) == same.end()) {
                ans = min(ans, f);
            }
        }
        for (int b : backs) {
            if (same.find(b) == same.end()) {
                ans = min(ans, b);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
