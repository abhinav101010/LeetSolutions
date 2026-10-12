class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return backtrack(nums, 0, 0);
    }
    
private:
    int backtrack(const vector<int>& nums, int i, int currentXor) {
        if (i == nums.size()) {
            return currentXor;
        }
        int include = backtrack(nums, i + 1, currentXor ^ nums[i]);
        int exclude = backtrack(nums, i + 1, currentXor);
        return include + exclude;
    }
};