#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](auto a, auto b) {
            int d1 = a[0]*a[0]+a[1]*a[1];
            int d2 = b[0]*b[0]+b[1]*b[1];
            return d1 < d2;
        });
        points.resize(k);
        return points;
    }
};
