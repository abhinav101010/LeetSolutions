class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> countMap;
        countMap[0] = -1;
        int count = 0;
        int maxLen = 0;
        
        for (int i = 0; i < (int)nums.size(); i++) {
            count += nums[i] == 1 ? 1 : -1;
            if (countMap.count(count)) {
                maxLen = max(maxLen, i - countMap[count]);
            } else {
                countMap[count] = i;
            }
        }
        
        return maxLen;
    }
};