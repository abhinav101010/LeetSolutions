#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<string, vector<pair<int,int>>> mp;
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i+1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int mx = x1 + x2;
                int my = y1 + y2;
                int dx = x1 - x2;
                int dy = y1 - y2;
                int dist2 = dx*dx + dy*dy;
                string key = to_string(mx) + "," + to_string(my) + "," + to_string(dist2);
                mp[key].push_back({dx, dy});
            }
        }
        double ans = 1e18;
        for (auto& kv : mp) {
            auto& vecs = kv.second;
            int m = vecs.size();
            if (m < 2) continue;
            for (int i = 0; i < m; i++) {
                int x1 = vecs[i].first;
                int y1 = vecs[i].second;
                for (int j = i+1; j < m; j++) {
                    int x2 = vecs[j].first;
                    int y2 = vecs[j].second;
                    double area = fabs((double)(x1*y2 - y1*x2)) / 2.0;
                    if (area > 0 && area < ans) {
                        ans = area;
                    }
                }
            }
        }
        return ans >= 1e17 ? 0.0 : ans;
    }
};
