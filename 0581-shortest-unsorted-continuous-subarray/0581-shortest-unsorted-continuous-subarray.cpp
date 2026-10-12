class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int left = 0, right = nums.size() - 1;
        while (left < (int)nums.size() && nums[left] == sorted[left]) left++;
        while (right > left && nums[right] == sorted[right]) right--;
        return right > left ? right - left + 1 : 0;
    }
};