class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> cnt{{0,1}};
        int sum = 0, ans = 0;
        for (int x : nums) {
            sum += x;
            ans += cnt[sum - goal];
            cnt[sum]++;
        }
        return ans;
    }
};
