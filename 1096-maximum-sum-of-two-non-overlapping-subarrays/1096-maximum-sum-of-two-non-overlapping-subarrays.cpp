#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size();
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) pref[i+1] = pref[i] + A[i];
        auto sumx = [&](int i, int j) { return pref[j] - pref[i]; };
        int ans = 0, maxL = 0, maxM = 0;
        for (int i = L + M - 1; i < n; i++) {
            maxL = max(maxL, sumx(i - M - L + 1, i - M + 1));
            maxM = max(maxM, sumx(i - M - L + 1, i - L + 1));
            ans = max(ans, max(maxL + sumx(i - M + 1, i + 1), maxM + sumx(i - L + 1, i + 1)));
        }
        return ans;
    }
};
