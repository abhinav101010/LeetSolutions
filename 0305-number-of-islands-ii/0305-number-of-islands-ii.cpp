class Solution {
public:
    vector<int> parent, sizeArr;
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        parent.assign(m * n, 0);
        for (int i = 0; i < m * n; i++) parent[i] = i;
        sizeArr.assign(m * n, 1);
        vector<bool> grid(m * n, false);
        vector<int> res;
        int count = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto &p : positions) {
            int r = p[0], c = p[1];
            int idx = r * n + c;
            if (!grid[idx]) {
                grid[idx] = true;
                count++;
                for (int i = 0; i < 4; i++) {
                    int nr = r + dirs[i][0], nc = c + dirs[i][1];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr * n + nc]) {
                        int r1 = find(idx), r2 = find(nr * n + nc);
                        if (r1 != r2) {
                            if (sizeArr[r1] < sizeArr[r2]) swap(r1, r2);
                            parent[r2] = r1;
                            sizeArr[r1] += sizeArr[r2];
                            count--;
                        }
                    }
                }
            }
            res.push_back(count);
        }
        return res;
    }
};