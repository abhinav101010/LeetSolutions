class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0;
        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();
        
        for (int i = 1; i < (int)arrays.size(); i++) {
            const auto& arr = arrays[i];
            res = max(res, max(abs(arr.back() - minVal), abs(maxVal - arr[0])));
            minVal = min(minVal, arr[0]);
            maxVal = max(maxVal, arr.back());
        }
        
        return res;
    }
};