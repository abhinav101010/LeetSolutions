#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1, ans = -1;
        while (l < r) {
            int s = nums[l] + nums[r];
            if (s < k) { ans = max(ans, s); l++; }
            else r--;
        }
        return ans;
    }
};
