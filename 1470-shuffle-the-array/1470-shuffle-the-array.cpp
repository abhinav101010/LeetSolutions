class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> newNums(2 * n);

        for (int i = 0; i < n; i++) {
            newNums[2 * i] = nums[i];
            newNums[2 * i + 1] = nums[n + i];
        }

        return newNums;
    }
};