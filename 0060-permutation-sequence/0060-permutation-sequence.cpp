class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact = 1;
        for (int i = 1; i < n; i++) {
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k -= 1;
        string ans;
        while (!nums.empty()) {
            int idx = k / fact;
            k %= fact;
            ans += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);
            if (!nums.empty()) {
                fact /= (int)nums.size();
            }
        }
        return ans;
    }
};
