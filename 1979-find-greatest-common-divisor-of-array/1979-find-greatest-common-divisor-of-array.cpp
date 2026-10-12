class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];
        for (int num : nums) {
            if (num < mn) mn = num;
            if (num > mx) mx = num;
        }
        return gcd(mn, mx);
    }

private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};