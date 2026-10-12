class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpLen(n, 1), dpCnt(n, 1);
        int maxLen = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dpLen[j] + 1 > dpLen[i]) {
                        dpLen[i] = dpLen[j] + 1;
                        dpCnt[i] = dpCnt[j];
                    } else if (dpLen[j] + 1 == dpLen[i]) {
                        dpCnt[i] += dpCnt[j];
                    }
                }
            }
            maxLen = max(maxLen, dpLen[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (dpLen[i] == maxLen) res += dpCnt[i];
        }
        return res;
    }
};