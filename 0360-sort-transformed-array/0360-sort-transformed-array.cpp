class Solution {
public:
    int func(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> res(n);
        int left = 0, right = n - 1;
        int idx = a >= 0 ? n - 1 : 0;
        while (left <= right) {
            int lVal = func(nums[left], a, b, c);
            int rVal = func(nums[right], a, b, c);
            if (a >= 0) {
                if (lVal >= rVal) {
                    res[idx--] = lVal;
                    left++;
                } else {
                    res[idx--] = rVal;
                    right--;
                }
            } else {
                if (lVal <= rVal) {
                    res[idx++] = lVal;
                    left++;
                } else {
                    res[idx++] = rVal;
                    right--;
                }
            }
        }
        return res;
    }
};