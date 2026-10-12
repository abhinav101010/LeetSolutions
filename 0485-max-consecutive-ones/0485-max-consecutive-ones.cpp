class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int length = 0;
        for (int num : nums) {
            if (num == 1) {
                ++length;
            } else {
                ans = max(ans, length);
                length = 0;
            }
        }
        return max(ans, length);
    }
};