#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <limits>
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
                long cx2 = (long)x1 + x2;
                long cy2 = (long)y1 + y2;
                long dx = x1 - x2;
                long dy = y1 - y2;
                long dist2 = dx*dx + dy*dy;
                string key = to_string(cx2) + "," + to_string(cy2) + "," + to_string(dist2);
                mp[key].push_back({i, j});
            }
        }
        double ans = numeric_limits<double>::infinity();
        for (auto& kv : mp) {
            auto& pairs = kv.second;
            int m = pairs.size();
            if (m < 2) continue;
            for (int a = 0; a < m; a++) {
                int i1 = pairs[a].first;
                int i2 = pairs[a].second;
                int x1 = points[i1][0], y1 = points[i1][1];
                int x3 = points[i2][0], y3 = points[i2][1];
                for (int b = a+1; b < m; b++) {
                    int j1 = pairs[b].first;
                    int j2 = pairs[b].second;
                    int x2 = points[j1][0], y2 = points[j1][1];
                    int x4 = points[j2][0], y4 = points[j2][1];
                    double area = fabs((double)(x1 - x3)*(y2 - y4) - (double)(y1 - y3)*(x2 - x4)) / 2.0;
                    if (area > 0) {
                        ans = min(ans, area);
                    }
                }
            }
        }
        return ans == numeric_limits<double>::infinity() ? 0.0 : ans;
    }
};
