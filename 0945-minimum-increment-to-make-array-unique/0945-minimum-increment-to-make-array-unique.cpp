#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.empty()) return 0;
        sort(A.begin(), A.end());
        int ans = 0;
        int prev = A[0];
        for (size_t i = 1; i < A.size(); i++) {
            if (A[i] <= prev) {
                ans += prev + 1 - A[i];
                prev = prev + 1;
            } else {
                prev = A[i];
            }
        }
        return ans;
    }
};
