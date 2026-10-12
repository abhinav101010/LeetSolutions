class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;
        
        vector<int> minLeft(nums.size());
        minLeft[0] = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            minLeft[i] = min(minLeft[i-1], nums[i]);
        }
        
        vector<int> stack;
        for (int j = nums.size() - 1; j >= 0; j--) {
            if (nums[j] > minLeft[j]) {
                while (!stack.empty() && stack.back() <= minLeft[j]) {
                    stack.pop_back();
                }
                if (!stack.empty() && stack.back() < nums[j]) {
                    return true;
                }
                stack.push_back(nums[j]);
            }
        }
        return false;
    }
};