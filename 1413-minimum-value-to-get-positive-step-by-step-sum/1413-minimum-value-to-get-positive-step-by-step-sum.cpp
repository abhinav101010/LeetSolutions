class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int total = 0;
        int minSum = 0;

        for (int num : nums) {
            total += num;
            minSum = min(minSum, total);
        }

        return 1 - minSum;
    }
};
