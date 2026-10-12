class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = (int)nums.size();
        int i = 1;
        bool start = false;
        while (i < n && nums[i] > nums[i - 1]) {
            i++;
            start = true;
            if (i == n) return false;
        }
        bool mid = false;
        while (i < n && nums[i] < nums[i - 1] && start) {
            i++;
            mid = true;
            if (i == n) return false;
        }
        bool end = false;
        while (i < n && nums[i] > nums[i - 1] && mid) {
            i++;
            end = true;
        }
        return start && mid && end && i == n;
    }
};