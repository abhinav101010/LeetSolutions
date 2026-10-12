class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            
            // Largest rectangle in histogram
            vector<pair<int, int>> stack;
            for (int k = 0; k < n; k++) {
                int start = k;
                while (!stack.empty() && stack.back().second > heights[k]) {
                    auto [idx, height] = stack.back();
                    stack.pop_back();
                    int area = height * (k - idx);
                    maxArea = max(maxArea, area);
                    start = idx;
                }
                stack.emplace_back(start, heights[k]);
            }
            
            for (auto [idx, height] : stack) {
                int area = height * (n - idx);
                maxArea = max(maxArea, area);
            }
        }
        
        return maxArea;
    }
};