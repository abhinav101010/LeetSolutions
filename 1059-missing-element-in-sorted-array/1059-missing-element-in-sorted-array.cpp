#include <vector>
using namespace std;
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] > 1) {
                int diff = nums[i] - nums[i-1] - 1;
                if (k <= diff) return nums[i-1] + k;
                k -= diff;
            }
        }
        return nums.back() + k;
    }
};
