class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;
        int max = 0;
        for (int num : nums) {
            if (num > max) max = num;
        }
        if (max != n - 1) return false;
        vector<int> count(max + 1, 0);
        for (int num : nums) {
            if (num < 1 || num > max) return false;
            count[num]++;
        }
        if (count[max] != 2) return false;
        for (int i = 1; i < max; i++) {
            if (count[i] != 1) return false;
        }
        return true;
    }
};