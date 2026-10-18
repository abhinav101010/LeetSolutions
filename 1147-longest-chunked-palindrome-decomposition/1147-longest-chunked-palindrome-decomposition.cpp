#include <string>
using namespace std;

class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        int ans = 0;
        int i = 0, j = n - 1;
        while (i <= j) {
            int k = 1;
            bool ok = false;
            while (i + k - 1 < j - k + 1) {
                if (text.substr(i, k) == text.substr(j - k + 1, k)) {
                    ans += 2;
                    i += k;
                    j -= k;
                    ok = true;
                    break;
                }
                k++;
            }
            if (!ok) {
                ans++;
                break;
            }
        }
        return ans;
    }
};
