class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = seen.find(nums[i]);
            if (it != seen.end()) {
                if (i - it->second <= k) {
                    return true;
                }
            }
            seen[nums[i]] = i;
        }
        return false;
    }
};