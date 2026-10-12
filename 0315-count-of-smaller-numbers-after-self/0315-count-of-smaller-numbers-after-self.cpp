class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        vector<pair<int, int>> enumVec;
        for (int i = 0; i < n; i++) {
            enumVec.emplace_back(i, nums[i]);
        }
        
        mergeSort(enumVec, 0, n - 1, result);
        return result;
    }
    
private:
    vector<pair<int, int>> mergeSort(vector<pair<int, int>>& arr, int left, int right, vector<int>& result) {
        if (left >= right) return {arr[left]};
        
        int mid = (left + right) / 2;
        vector<pair<int, int>> leftArr = mergeSort(arr, left, mid, result);
        vector<pair<int, int>> rightArr = mergeSort(arr, mid + 1, right, result);
        
        vector<pair<int, int>> merged;
        merged.reserve(right - left + 1);
        int i = 0, j = 0;
        while (i < (int)leftArr.size() || j < (int)rightArr.size()) {
            if (j == (int)rightArr.size() || (i < (int)leftArr.size() && leftArr[i].second <= rightArr[j].second)) {
                result[leftArr[i].first] += j;
                merged.push_back(leftArr[i++]);
            } else {
                merged.push_back(rightArr[j++]);
            }
        }
        return merged;
    }
};