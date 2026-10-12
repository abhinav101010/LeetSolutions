class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int num = left; num <= right; num++) {
            if (selfDividing(num)) ans.push_back(num);
        }
        return ans;
    }

private:
    bool selfDividing(int num) {
        for (int n = num; n > 0; n /= 10) {
            int digit = n % 10;
            if (digit == 0 || num % digit != 0) return false;
        }
        return true;
    }
};