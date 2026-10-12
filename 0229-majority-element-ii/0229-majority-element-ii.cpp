class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> seen;
        vector<int> ans;

        for (int num : nums) {
            seen[num]++;
        }

        int threshold = nums.size() / 3;
        for (auto& [num, count] : seen) {
            if (count > threshold) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};