class Solution {
private:
    unordered_map<int, vector<int>> valToIndices;
    
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); i++) {
            valToIndices[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        auto& indices = valToIndices[target];
        return indices[rand() % indices.size()];
    }
};