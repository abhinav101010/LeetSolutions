class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        vector<int> stack;
        
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;
            while (!stack.empty() && stack.back() <= nums[idx]) {
                stack.pop_back();
            }
            if (i < n && !stack.empty()) {
                result[idx] = stack.back();
            }
            stack.push_back(nums[idx]);
        }
        
        return result;
    }
};