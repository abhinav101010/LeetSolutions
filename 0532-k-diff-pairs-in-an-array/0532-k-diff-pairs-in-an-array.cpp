class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<int, int> count;
        for (int num : nums) count[num]++;
        
        int result = 0;
        if (k == 0) {
            for (auto& [_, v] : count) {
                if (v > 1) result++;
            }
        } else {
            for (auto& [num, _] : count) {
                if (count.count(num + k)) result++;
            }
        }
        return result;
    }
};