class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        vector<char> used(nums.size(), 0);
        backtrack(nums, used, cur, ans);
        return ans;
    }

private:
    void backtrack(vector<int>& nums, vector<char>& used, vector<int>& cur, vector<vector<int>>& ans) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < (int)nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            used[i] = 1;
            cur.push_back(nums[i]);
            backtrack(nums, used, cur, ans);
            cur.pop_back();
            used[i] = 0;
        }
    }
};
