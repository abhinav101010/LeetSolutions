#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> left, right, count;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (left.find(x) == left.end()) {
                left[x] = i;
            }
            right[x] = i;
            count[x]++;
        }
        int degree = 0;
        for (auto& p : count) {
            degree = max(degree, p.second);
        }
        int ans = n;
        for (auto& p : count) {
            int x = p.first;
            if (p.second == degree) {
                ans = min(ans, right[x] - left[x] + 1);
            }
        }
        return ans;
    }
};
