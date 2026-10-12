class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mn = nums[0], mx = nums[0];
        for (int num : nums) {
            mn = min(mn, num);
            mx = max(mx, num);
        }
        return max(0, mx - mn - 2 * k);
    }
};