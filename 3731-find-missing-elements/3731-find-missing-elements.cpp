class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = (int)nums.size();
        int mn = nums[0], mx = nums[0];
        unordered_set<int> st;
        for (int x : nums) {
            st.insert(x);
            if (x < mn) mn = x;
            if (x > mx) mx = x;
        }
        vector<int> ans;
        for (int i = mn; i <= mx; i++) {
            if (!st.count(i)) ans.push_back(i);
        }
        return ans;
    }
};