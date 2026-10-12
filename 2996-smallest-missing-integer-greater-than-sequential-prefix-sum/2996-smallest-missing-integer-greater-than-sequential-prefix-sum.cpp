class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int total = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                total += nums[i];
            } else {
                break;
            }
        }
        vector<bool> seen(51, false);
        for (int num : nums) {
            if (num <= 50) seen[num] = true;
        }
        while (seen[total]) {
            total++;
        }
        return total;
    }
};