class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int duplicate = -1;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                duplicate = nums[i];
                break;
            }
        }
        for (int i = 1; i <= (int)nums.size(); i++) {
            bool found = false;
            for (int j = 0; j < (int)nums.size(); j++) {
                if (nums[j] == i) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return vector<int>{duplicate, i};
            }
        }
        return vector<int>{duplicate, (int)nums.size()};
    }
};
