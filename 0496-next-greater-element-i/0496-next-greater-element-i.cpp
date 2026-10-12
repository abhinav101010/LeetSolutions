class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        vector<int> stack;
        
        for (int num : nums2) {
            while (!stack.empty() && stack.back() < num) {
                nextGreater[stack.back()] = num;
                stack.pop_back();
            }
            stack.push_back(num);
        }
        
        vector<int> ans;
        ans.reserve(nums1.size());
        for (int num : nums1) {
            auto it = nextGreater.find(num);
            ans.push_back(it != nextGreater.end() ? it->second : -1);
        }
        return ans;
    }
};