#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs[0].size();
        int n = strs.size();
        vector<bool> sorted(n-1, false); // sorted[i] = true if strs[i] < strs[i+1] already
        int ans = 0;
        for (int col = 0; col < m; col++) {
            bool deleteCol = false;
            for (int i = 0; i < n-1; i++) {
                if (!sorted[i] && strs[i][col] > strs[i+1][col]) {
                    deleteCol = true;
                    break;
                }
            }
            if (deleteCol) {
                ans++;
            } else {
                for (int i = 0; i < n-1; i++) {
                    if (!sorted[i] && strs[i][col] < strs[i+1][col]) {
                        sorted[i] = true;
                    }
                }
            }
        }
        return ans;
    }
};
