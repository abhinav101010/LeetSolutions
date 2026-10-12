#include <vector>
#include <algorithm>

class Solution {
public:
    int heightChecker(std::vector<int>& heights) {
        std::vector<int> expected = heights;
        std::sort(expected.begin(), expected.end());

        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != expected[i]) {
                ans++;
            }
        }
        return ans;
    }
};