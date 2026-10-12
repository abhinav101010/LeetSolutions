class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int highest = nums[0];
        int least = nums[0];
        int ans = nums[0];

        for (int i = 1; i < (int)nums.size(); i++) {
            int num = nums[i];
            if (num < 0) {
                swap(highest, least);
            }
            highest = max(num, highest * num);
            least = min(num, least * num);
            ans = max(ans, highest);
        }
        return ans;
    }
};