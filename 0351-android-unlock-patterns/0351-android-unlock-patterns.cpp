class Solution {
public:
    int res = 0;
    void dfs(int curr, int remain, vector<bool>& visited, vector<vector<int>>& skip) {
        if (remain == 0) {
            res++;
            return;
        }
        for (int i = 1; i <= 9; i++) {
            if (!visited[i] && (skip[curr][i] == 0 || visited[skip[curr][i]])) {
                visited[i] = true;
                dfs(i, remain - 1, visited, skip);
                visited[i] = false;
            }
        }
    }
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> skip(10, vector<int>(10, 0));
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;
        vector<bool> visited(10, false);
        res = 0;
        for (int i = m; i <= n; i++) {
            for (int j = 1; j <= 9; j++) {
                visited[j] = true;
                dfs(j, i - 1, visited, skip);
                visited[j] = false;
            }
        }
        return res;
    }
};