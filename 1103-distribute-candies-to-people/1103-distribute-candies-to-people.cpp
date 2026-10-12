#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> distributeCandies(int candies, int num_people) {
        std::vector<int> ans(num_people, 0);

        int i = 0;
        while (candies > 0) {
            int give = std::min(candies, i + 1);
            ans[i % num_people] += give;
            candies -= give;
            i++;
        }

        return ans;
    }
};