class Solution {
public:
    int gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int mxi = 0;
        for (int i = 0; i < n; i++) {
            mxi = max(mxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], mxi);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int ans = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            ans += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        return ans;
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
};