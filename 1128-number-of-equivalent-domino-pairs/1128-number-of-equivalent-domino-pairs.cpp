#include <vector>
#include <unordered_map>

class Solution {
public:
    int numEquivDominoPairs(std::vector<std::vector<int>>& dominoes) {
        std::unordered_map<int, int> count;
        int ans = 0;

        for (auto& d : dominoes) {
            int key = std::min(d[0], d[1]) * 10 + std::max(d[0], d[1]);

            ans += count[key];
            count[key]++;
        }

        return ans;
    }
};