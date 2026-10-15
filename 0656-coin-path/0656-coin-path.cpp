#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        int n = A.size();
        if (n == 0 || A[0] == -1 || A[n-1] == -1) {
            return {};
        }
        const long long INF = LLONG_MAX;
        vector<long long> dpCost(n, INF);
        vector<vector<int>> dpPath(n);
        dpCost[0] = A[0];
        dpPath[0] = {1};
        for (int i = 1; i < n; i++) {
            if (A[i] == -1) continue;
            int start = max(0, i - B);
            for (int j = start; j < i; j++) {
                if (dpCost[j] == INF) continue;
                long long candCost = dpCost[j] + A[i];
                vector<int> candPath = dpPath[j];
                candPath.push_back(i + 1);
                if (candCost < dpCost[i]) {
                    dpCost[i] = candCost;
                    dpPath[i] = move(candPath);
                } else if (candCost == dpCost[i]) {
                    if (lexicographicallySmaller(candPath, dpPath[i])) {
                        dpPath[i] = move(candPath);
                    }
                }
            }
        }
        if (dpCost[n-1] == INF) {
            return {};
        }
        return dpPath[n-1];
    }
    
private:
    bool lexicographicallySmaller(const vector<int>& a, const vector<int>& b) {
        int len = min(a.size(), b.size());
        for (int i = 0; i < len; i++) {
            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        }
        return a.size() < b.size();
    }
};
