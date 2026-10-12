class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        sub(0, nums, cur, ans);
        return ans;
    }

private:
    void sub(int i, vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans) {
        if (i == (int)nums.size()) {
            ans.push_back(cur);
            return;
        }

        sub(i + 1, nums, cur, ans);
        cur.push_back(nums[i]);
        sub(i + 1, nums, cur, ans);
        cur.pop_back();
    }
};
