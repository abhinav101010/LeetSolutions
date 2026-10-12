class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int curr = 0;
        for (int num : nums) {
            curr = (curr * 2 + num) % 5;
            ans.push_back(curr == 0);
        }
        return ans;
    }
};
