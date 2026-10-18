#include <vector>
using namespace std;

class Solution {
public:
    vector<int> selectData(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == target) res.push_back(i);
        }
        return res;
    }
};
