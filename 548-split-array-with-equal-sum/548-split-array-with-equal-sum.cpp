#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 7) return false;
        vector<int> prefix(n+1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }
        for (int j = 3; j < n-3; j++) {
            unordered_set<int> leftSums;
            for (int i = 1; i < j-1; i++) {
                int sum1 = prefix[i] - prefix[0];
                int sum2 = prefix[j] - prefix[i+1];
                if (sum1 == sum2) {
                    leftSums.insert(sum1);
                }
            }
            for (int k = j+2; k < n-1; k++) {
                int sum3 = prefix[k] - prefix[j+1];
                int sum4 = prefix[n] - prefix[k+1];
                if (sum3 == sum4 && leftSums.find(sum3) != leftSums.end()) {
                    return true;
                }
            }
        }
        return false;
    }
};
