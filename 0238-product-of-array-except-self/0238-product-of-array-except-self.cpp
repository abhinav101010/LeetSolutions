class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeroCount = 0;

        for (int num : nums) {
            if (num != 0) {
                product *= num;
            } else {
                zeroCount++;
            }
        }

        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            if (zeroCount > 1) {
                ans[i] = 0;
            } else if (zeroCount == 1) {
                if (nums[i] == 0) {
                    ans[i] = product;
                } else {
                    ans[i] = 0;
                }
            } else {
                ans[i] = product / nums[i];
            }
        }

        return ans;
    }
};