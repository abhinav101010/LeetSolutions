#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;
        int prefix = 0;
        int ans = 0;
        for (int num : nums) {
            prefix = ((prefix % k) + k) % k;
            ans += count[prefix];
            count[prefix]++;
        }
        return ans;
    }
};
