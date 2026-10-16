#include <vector>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            if (nums[right] == 0) k--;
            if (k < 0) {
                if (nums[left] == 0) k++;
                left++;
            }
        }
        return (int)nums.size() - left;
    }
};
