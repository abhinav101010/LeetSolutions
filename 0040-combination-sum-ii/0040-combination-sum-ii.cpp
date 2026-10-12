class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
        for (int i = start; i < (int)candidates.size(); i++) {
            if (candidates[i] > target) {
                break;
            }
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            cur.push_back(candidates[i]);
            backtrack(candidates, i + 1, target - candidates[i], cur, ans);
            cur.pop_back();
        }
    }
};
