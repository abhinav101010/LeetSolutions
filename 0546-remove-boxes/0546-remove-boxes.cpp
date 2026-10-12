class Solution {
private:
    vector<int> boxes;
    vector<vector<vector<int>>> memo;
    
    int dp(int l, int r, int k) {
        if (l > r) return 0;
        if (memo[l][r][k] != 0) return memo[l][r][k];
        
        while (l < r && boxes[r] == boxes[r - 1]) {
            r--;
            k++;
        }
        
        int res = dp(l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                res = max(res, dp(l, i, k + 1) + dp(i + 1, r - 1, 0));
            }
        }
        
        memo[l][r][k] = res;
        return res;
    }

public:
    int removeBoxes(vector<int>& boxes) {
        this->boxes = boxes;
        int n = boxes.size();
        memo.assign(n, vector<vector<int>>(n, vector<int>(n, 0)));
        return dp(0, n - 1, 0);
    }
};