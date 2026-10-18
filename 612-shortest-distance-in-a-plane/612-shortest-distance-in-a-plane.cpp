#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

struct Point {
    int x;
    int y;
};

class Solution {
public:
    double shortestDistance(vector<Point>& points) {
        int n = (int)points.size();
        if (n < 2) return 0.0;
        long long minSq = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long dx = (long long)points[i].x - (long long)points[j].x;
                long long dy = (long long)points[i].y - (long long)points[j].y;
                long long sq = dx * dx + dy * dy;
                if (sq < minSq) minSq = sq;
            }
        }
        double d = sqrt((double)minSq);
        return round(d * 100.0) / 100.0;
    }
};
