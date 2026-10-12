class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxLen = 0;
        vector<bool> visited(nums.size(), false);
        
        for (int i = 0; i < (int)nums.size(); i++) {
            if (!visited[i]) {
                int count = 0;
                int curr = i;
                while (!visited[curr]) {
                    visited[curr] = true;
                    curr = nums[curr];
                    count++;
                }
                maxLen = max(maxLen, count);
            }
        }
        
        return maxLen;
    }
};