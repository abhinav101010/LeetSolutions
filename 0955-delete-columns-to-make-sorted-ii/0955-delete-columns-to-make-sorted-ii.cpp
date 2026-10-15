#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<bool> sorted(n-1, false);
        int ans = 0;
        for (int col = 0; col < m; col++) {
            bool ok = true;
            for (int i = 0; i < n-1; i++) {
                if (!sorted[i] && strs[i][col] > strs[i+1][col]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                ans++;
                continue;
            }
            for (int i = 0; i < n-1; i++) {
                if (!sorted[i] && strs[i][col] < strs[i+1][col]) {
                    sorted[i] = true;
                }
            }
        }
        return ans;
    }
};
