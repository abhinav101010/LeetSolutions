#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return score[a] > score[b];
        });
        
        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            int idx = indices[i];
            if (i == 0) ans[idx] = "Gold Medal";
            else if (i == 1) ans[idx] = "Silver Medal";
            else if (i == 2) ans[idx] = "Bronze Medal";
            else ans[idx] = to_string(i + 1);
        }
        return ans;
    }
};