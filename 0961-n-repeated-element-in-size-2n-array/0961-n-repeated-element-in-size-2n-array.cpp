class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (!seen.insert(num).second) {
                return num;
            }
        }
        return 0;
    }
};