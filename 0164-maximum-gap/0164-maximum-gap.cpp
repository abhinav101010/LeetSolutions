class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = (int)nums.size();
        if (n < 2) return 0;

        int loVal = nums[0];
        int hiVal = nums[0];
        for (int num : nums) {
            if (num < loVal) loVal = num;
            if (num > hiVal) hiVal = num;
        }
        if (loVal == hiVal) return 0;

        int bucketSize = std::max(1, (hiVal - loVal) / (n - 1));
        int bucketCount = (hiVal - loVal) / bucketSize + 1;
        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);

        for (int num : nums) {
            int idx = (num - loVal) / bucketSize;
            bucketMin[idx] = std::min(bucketMin[idx], num);
            bucketMax[idx] = std::max(bucketMax[idx], num);
        }

        int ans = 0;
        int prevMax = bucketMax[0];
        for (int i = 1; i < bucketCount; i++) {
            if (bucketMin[i] == INT_MAX) continue;
            ans = std::max(ans, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }
        return ans;
    }
};