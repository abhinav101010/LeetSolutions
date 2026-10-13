class Solution {
public:
    vector<vector<int>> res;
    
    void dfs(int start, vector<int> path, int remain) {
        if (remain == 1) {
            if (path.size() > 1) {
                res.push_back(path);
            }
            return;
        }
        for (int i = start; i <= sqrt(remain); i++) {
            if (remain % i == 0) {
                path.push_back(i);
                dfs(i, path, remain / i);
                path.pop_back();
            }
        }
        path.push_back(remain);
        dfs(remain, path, 1);
        path.pop_back();
    }
    
    vector<vector<int>> getFactors(int n) {
        vector<int> path;
        dfs(2, path, n);
        return res;
    }
};