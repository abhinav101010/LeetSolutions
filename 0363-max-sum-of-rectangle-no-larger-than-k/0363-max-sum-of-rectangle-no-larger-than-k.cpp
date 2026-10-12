class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int maxSum = INT_MIN;
        
        for (int left = 0; left < n; left++) {
            vector<int> rowSums(m, 0);
            for (int right = left; right < n; right++) {
                for (int i = 0; i < m; i++) {
                    rowSums[i] += matrix[i][right];
                }
                
                set<int> sortedPrefix = {0};
                int prefix = 0;
                for (int s : rowSums) {
                    prefix += s;
                    auto it = sortedPrefix.lower_bound(prefix - k);
                    if (it != sortedPrefix.end()) {
                        maxSum = max(maxSum, prefix - *it);
                    }
                    sortedPrefix.insert(prefix);
                }
            }
        }
        
        return maxSum;
    }
};