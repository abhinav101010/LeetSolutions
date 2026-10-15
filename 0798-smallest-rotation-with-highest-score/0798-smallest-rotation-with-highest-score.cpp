#include <vector>
using namespace std;

class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> change(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int left = (i + 1) % n;
            int right = (i - val + n + 1) % n;
            change[left]++;
            change[right]--;
            if (left > right) {
                change[0]++;
            }
        }
        int best = 0;
        int maxScore = -1;
        int cur = 0;
        for (int k = 0; k < n; k++) {
            cur += change[k];
            if (cur > maxScore) {
                maxScore = cur;
                best = k;
            }
        }
        return best;
    }
};
