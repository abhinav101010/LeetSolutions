class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = nums[0], idx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
                idx = i;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i != idx && max < 2 * nums[i]) return -1;
        }
        return idx;
    }
};