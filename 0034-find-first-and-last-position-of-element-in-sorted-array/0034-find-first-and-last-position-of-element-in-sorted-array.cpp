class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);
        if (first == (int)nums.size() || nums[first] != target) {
            return {-1, -1};
        }
        return {first, upperBound(nums, target) - 1};
    }

private:
    int lowerBound(vector<int>& nums, int target) {
        int lo = 0;
        int hi = (int)nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }

    int upperBound(vector<int>& nums, int target) {
        int lo = 0;
        int hi = (int)nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
