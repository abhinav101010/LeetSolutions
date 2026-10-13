class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        vector<string> pairs[5] = {{"0","0"}, {"1","1"}, {"6","9"}, {"8","8"}, {"9","6"}};
        string path(n, ' ');
        function<void(int,int)> dfs = [&](int left, int right) {
            if (left > right) {
                res.push_back(path);
                return;
            }
            for (auto &p : pairs) {
                if (left == 0 && right == n - 1 && p[0] == "0" && n > 1) continue;
                if (left == right && p[0] != p[1]) continue;
                path[left] = p[0][0];
                path[right] = p[1][0];
                dfs(left + 1, right - 1);
            }
        };
        dfs(0, n - 1);
        return res;
    }
};