#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        for (int j = 3; j < n - 1; ++j) {
            unordered_set<int> s;
            for (int i = 1; i < j - 1; ++i) {
                if (sum[i] == sum[j] - sum[i + 1]) {
                    s.insert(sum[i]);
                }
            }
            for (int k = j + 2; k < n; ++k) {
                if (sum[n] - sum[k + 1] == sum[k] - sum[j + 1] && s.count(sum[n] - sum[k + 1])) {
                    return true;
                }
            }
        }
        return false;
    }
};
