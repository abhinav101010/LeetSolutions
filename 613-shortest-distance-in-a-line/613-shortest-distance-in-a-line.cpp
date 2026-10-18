#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Point { int x; };

class Solution {
public:
    int shortestDistance(vector<Point>& points) {
        int n = (int)points.size();
        if (n < 2) return 0;
        int best = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int d = abs(points[i].x - points[j].x);
                if (d < best) best = d;
            }
        }
        return best == INT_MAX ? 0 : best;
    }
};
