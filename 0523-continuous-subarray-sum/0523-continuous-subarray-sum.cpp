class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> modMap;
        modMap[0] = -1;
        int prefixSum = 0;
        
        for (int i = 0; i < (int)nums.size(); i++) {
            prefixSum += nums[i];
            int mod = prefixSum % k;
            if (modMap.count(mod)) {
                if (i - modMap[mod] >= 2) return true;
            } else {
                modMap[mod] = i;
            }
        }
        
        return false;
    }
};