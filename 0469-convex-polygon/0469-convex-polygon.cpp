#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    long cross(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
        return (long)(b[0] - a[0]) * (c[1] - b[1]) - (long)(b[1] - a[1]) * (c[0] - b[0]);
    }
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 3) return false;
        int cur = 0, prev = 0;
        for (int i = 0; i < n; ++i) {
            long c = cross(points[i], points[(i + 1) % n], points[(i + 2) % n]);
            if (c != 0) {
                if (cur == 0) cur = (c > 0) ? 1 : -1;
                else if ((c > 0 && cur < 0) || (c < 0 && cur > 0)) return false;
            }
        }
        return true;
    }
};
