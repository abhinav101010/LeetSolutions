class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for (int num : nums) {
            int sum = 0;
            int n = num;
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }
            ans = min(ans, sum);
        }
        return ans;
    }
};