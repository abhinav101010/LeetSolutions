class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        combine(1, n, k, cur, ans);
        return ans;
    }

private:
    void combine(int start, int n, int k, vector<int>& cur, vector<vector<int>>& ans) {
        if ((int)cur.size() == k) {
            ans.push_back(cur);
            return;
        }

        for (int i = start; i <= n; i++) {
            cur.push_back(i);
            combine(i + 1, n, k, cur, ans);
            cur.pop_back();
        }
    }
};
