class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            leftSum += nums[i];
            rightSum -= nums[i];
            if (leftSum - nums[i] == rightSum) return i;
        }
        return -1;
    }
};