class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long bitwise = 0;
        for (int num : nums) {
            bitwise ^= num;
        }

        int diff = bitwise & -bitwise;
        vector<int> ans(2);
        for (int num : nums) {
            if ((num & diff) == 0) {
                ans[0] ^= num;
            } else {
                ans[1] ^= num;
            }
        }
        return ans;
    }
};
