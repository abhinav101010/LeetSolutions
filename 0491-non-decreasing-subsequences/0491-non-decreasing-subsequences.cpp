class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> path;
        backtrack(nums, 0, path, result);
        return vector<vector<int>>(result.begin(), result.end());
    }
    
private:
    void backtrack(const vector<int>& nums, int start, vector<int>& path, set<vector<int>>& result) {
        if (path.size() >= 2) {
            result.insert(path);
        }
        if (start >= (int)nums.size()) return;
        
        unordered_set<int> used;
        for (int i = start; i < (int)nums.size(); i++) {
            if (used.count(nums[i])) continue;
            if (path.empty() || nums[i] >= path.back()) {
                used.insert(nums[i]);
                path.push_back(nums[i]);
                backtrack(nums, i + 1, path, result);
                path.pop_back();
            }
        }
    }
};