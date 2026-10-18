#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    vector<ll> h, p;
    vector<vector<int>> paths;
    unordered_map<ll,int> cnt;
    bool check(int mid) {
        cnt.clear();
        p.assign(100005, 1LL);
        for (size_t j = 0; j < paths.size(); ++j) {
            int npath = paths[j].size();
            h.assign(npath + 1, 0LL);
            for (int i = 1; i <= npath; ++i) {
                p[i] = p[i - 1] * 133331LL;
                h[i] = h[i - 1] * 133331LL + paths[j][i - 1];
            }
            unordered_set<ll> seen;
            for (int i = mid; i <= npath; ++i) {
                ll val = h[i] - h[i - mid] * p[mid];
                if (seen.find(val) == seen.end()) {
                    seen.insert(val);
                    cnt[val]++;
                }
            }
        }
        for (auto& pr : cnt) {
            if (pr.second == (int)paths.size()) return true;
        }
        return false;
    }
    int longestCommonSubpath(int n, vector<vector<int>>& paths_) {
        paths = paths_;
        int right = 100005;
        for (auto& path : paths) {
            right = min(right, (int)path.size());
        }
        int left = 0;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (check(mid)) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};
