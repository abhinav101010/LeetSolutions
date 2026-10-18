#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
    int atMost(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        int l = 0, res = 0;
        for (int r = 0; r < (int)nums.size(); r++) {
            count[nums[r]]++;
            while ((int)count.size() > k) {
                count[nums[l]]--;
                if (count[nums[l]] == 0) count.erase(nums[l]);
                l++;
            }
            res += r - l + 1;
        }
        return res;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};
