class Solution {
private:
    long count = 0;
    
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        count = 0;
        mergeSort(prefix, 0, n, lower, upper);
        return (int)count;
    }
    
private:
    vector<long long> mergeSort(vector<long long>& arr, int left, int right, int lower, int upper) {
        if (right - left <= 1) return {arr[left]};
        
        int mid = left + (right - left) / 2;
        vector<long long> leftArr = mergeSort(arr, left, mid, lower, upper);
        vector<long long> rightArr = mergeSort(arr, mid, right, lower, upper);
        
        // Count valid pairs
        int j = 0, k = 0;
        for (long long lVal : leftArr) {
            while (j < (int)rightArr.size() && rightArr[j] - lVal < lower) j++;
            while (k < (int)rightArr.size() && rightArr[k] - lVal <= upper) k++;
            count += k - j;
        }
        
        // Merge
        vector<long long> merged;
        merged.reserve(leftArr.size() + rightArr.size());
        int p = 0, q = 0;
        while (p < (int)leftArr.size() || q < (int)rightArr.size()) {
            if (q == (int)rightArr.size() || (p < (int)leftArr.size() && leftArr[p] <= rightArr[q])) {
                merged.push_back(leftArr[p++]);
            } else {
                merged.push_back(rightArr[q++]);
            }
        }
        return merged;
    }
};