#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> sumToIndex;
        sumToIndex[0] = -1;
        int prefixSum = 0;
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            if (sumToIndex.find(prefixSum - k) != sumToIndex.end()) {
                maxLen = max(maxLen, i - sumToIndex[prefixSum - k]);
            }
            if (sumToIndex.find(prefixSum) == sumToIndex.end()) {
                sumToIndex[prefixSum] = i;
            }
        }
        return maxLen;
    }
};
