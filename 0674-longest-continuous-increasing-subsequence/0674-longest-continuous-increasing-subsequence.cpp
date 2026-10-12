class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0;
        int curr = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i > 0 && nums[i] > nums[i - 1]) {
                curr++;
            } else {
                if (curr > ans) {
                    ans = curr;
                }
                curr = 1;
            }
        }
        return curr > ans ? curr : ans;
    }
};
