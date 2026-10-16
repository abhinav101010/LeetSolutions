#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int k = 0;
        for (int x : data) k += x;
        if (k <= 1) return 0;
        int zeros = 0;
        for (int i = 0; i < k; i++) if (data[i] == 0) zeros++;
        int ans = zeros;
        for (int i = k; i < (int)data.size(); i++) {
            if (data[i-k] == 0) zeros--;
            if (data[i] == 0) zeros++;
            ans = min(ans, zeros);
        }
        return ans;
    }
};
