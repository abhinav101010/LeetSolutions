class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> count(101, 0);

        for (int num : nums) {
            count[num]++;
        }

        int total = 0;

        for (int num = 1; num <= 100; num++) {
            if (count[num] == 1) {
                total += num;
            }
        }

        return total;
    }
};