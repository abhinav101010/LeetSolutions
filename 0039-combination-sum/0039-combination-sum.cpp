class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> cur;
        backtrack(candidates, 0, target, cur, ans);
        return ans;
    }

private:
    void backtrack(vector<int>& candidates, int start, int target, vector<int>& cur, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        for (int i = start; i < (int)candidates.size() && candidates[i] <= target; i++) {
            cur.push_back(candidates[i]);
            backtrack(candidates, i, target - candidates[i], cur, ans);
            cur.pop_back();
        }
    }
};
