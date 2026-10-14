#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int m = n - k + 1;
        vector<int> w(m, 0);
        int sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        w[0] = sum;
        for (int i = 1; i < m; i++) {
            sum += nums[i + k - 1] - nums[i - 1];
            w[i] = sum;
        }
        vector<int> left(m, 0);
        int best = 0;
        for (int i = 0; i < m; i++) {
            if (w[i] > w[best]) {
                best = i;
            }
            left[i] = best;
        }
        vector<int> right(m, 0);
        best = m - 1;
        for (int i = m - 1; i >= 0; i--) {
            if (w[i] >= w[best]) {
                best = i;
            }
            right[i] = best;
        }
        int maxSum = -1;
        vector<int> ans(3);
        for (int j = k; j < m - k; j++) {
            int i = left[j - k];
            int l = right[j + k];
            int total = w[i] + w[j] + w[l];
            if (total > maxSum) {
                maxSum = total;
                ans[0] = i;
                ans[1] = j;
                ans[2] = l;
            }
        }
        return ans;
    }
};
