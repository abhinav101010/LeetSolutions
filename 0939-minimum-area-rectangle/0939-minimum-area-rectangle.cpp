#include <vector>
#include <unordered_set>
#include <climits>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<long long> set;
        for (auto& p : points) {
            long long key = ((long long) p[0] << 32) | (p[1] & 0xffffffffLL);
            set.insert(key);
        }
        int ans = INT_MAX;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i+1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2 || y1 == y2) continue;
                long long key1 = ((long long) x1 << 32) | (y2 & 0xffffffffLL);
                long long key2 = ((long long) x2 << 32) | (y1 & 0xffffffffLL);
                if (set.count(key1) && set.count(key2)) {
                    int area = abs(x1 - x2) * abs(y1 - y2);
                    if (area < ans) ans = area;
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
