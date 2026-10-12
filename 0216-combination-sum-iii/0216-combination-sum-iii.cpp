class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(1, k, n, path, result);
        return result;
    }
    
private:
    void backtrack(int start, int k, int remaining, vector<int>& path, vector<vector<int>>& result) {
        if ((int)path.size() == k) {
            if (remaining == 0) {
                result.push_back(path);
            }
            return;
        }
        
        for (int i = start; i <= 9; i++) {
            if (i > remaining) break;
            path.push_back(i);
            backtrack(i + 1, k, remaining - i, path, result);
            path.pop_back();
        }
    }
};