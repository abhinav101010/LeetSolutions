#include <vector>
using namespace std;

class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 3) return false;
        long sign = 0;
        for (int i = 0; i < n; i++) {
            vector<int>& A = points[i];
            vector<int>& B = points[(i+1)%n];
            vector<int>& C = points[(i+2)%n];
            long x1 = B[0] - A[0];
            long y1 = B[1] - A[1];
            long x2 = C[0] - B[0];
            long y2 = C[1] - B[1];
            long cp = x1 * y2 - y1 * x2;
            if (cp != 0) {
                if (sign == 0) {
                    sign = cp > 0 ? 1 : -1;
                } else {
                    if ((cp > 0 && sign < 0) || (cp < 0 && sign > 0)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
