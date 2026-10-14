#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0;
        for (int v : nums) total += v;
        if (total % k != 0) return false;
        int target = total / k;
        sort(nums.rbegin(), nums.rend());
        if (nums[0] > target) return false;
        vector<bool> used(nums.size(), false);
        return backtrack(nums, used, 0, k, 0, target);
    }
    
private:
    bool backtrack(vector<int>& nums, vector<bool>& used, int start, int kRemain, int curSum, int target) {
        if (kRemain == 0) return true;
        if (curSum == target) {
            return backtrack(nums, used, 0, kRemain - 1, 0, target);
        }
        for (int i = start; i < nums.size(); i++) {
            if (!used[i] && curSum + nums[i] <= target) {
                used[i] = true;
                if (backtrack(nums, used, i + 1, kRemain, curSum + nums[i], target)) {
                    return true;
                }
                used[i] = false;
            }
        }
        return false;
    }
};
