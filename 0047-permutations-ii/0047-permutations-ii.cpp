class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        permute(nums, 0, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }

private:
    void permute(vector<int>& nums, int start, set<vector<int>>& ans) {
        if (start == (int)nums.size()) {
            ans.insert(nums);
            return;
        }
        for (int i = start; i < (int)nums.size(); i++) {
            swap(nums[i], nums[start]);
            permute(nums, start + 1, ans);
            swap(nums[i], nums[start]);
        }
    }
};
