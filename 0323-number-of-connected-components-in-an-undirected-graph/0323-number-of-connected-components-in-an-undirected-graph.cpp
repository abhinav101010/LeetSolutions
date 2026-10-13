class Solution {
public:
    vector<int> parent, sizeArr;
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        sizeArr.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
        int count = n;
        for (auto &e : edges) {
            int rx = find(e[0]), ry = find(e[1]);
            if (rx != ry) {
                if (sizeArr[rx] < sizeArr[ry]) swap(rx, ry);
                parent[ry] = rx;
                sizeArr[rx] += sizeArr[ry];
                count--;
            }
        }
        return count;
    }
};