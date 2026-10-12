class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }

private:
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        int pivot = nums[right];
        int p = left;
        for (int i = left; i < right; ++i) {
            if (nums[i] > pivot) {
                swap(nums[i], nums[p]);
                ++p;
            }
        }
        swap(nums[p], nums[right]);
        if (p == k - 1) return nums[p];
        if (p > k - 1) return quickSelect(nums, left, p - 1, k);
        return quickSelect(nums, p + 1, right, k);
    }
};