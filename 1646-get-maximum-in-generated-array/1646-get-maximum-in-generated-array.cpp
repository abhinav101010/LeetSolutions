class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) {
            return 0;
        }

        vector<int> nums(n + 1);
        nums[1] = 1;

        int maxVal = 1;
        for (int i = 2; i <= n; i++) {
            if (i % 2 == 0) {
                nums[i] = nums[i / 2];
            } else {
                nums[i] = nums[i / 2] + nums[i / 2 + 1];
            }
            if (nums[i] > maxVal) {
                maxVal = nums[i];
            }
        }

        return maxVal;
    }
};