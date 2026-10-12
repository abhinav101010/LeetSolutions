class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> stack; // {index, height}
        int maxArea = 0;
        
        for (int i = 0; i < (int)heights.size(); i++) {
            int start = i;
            while (!stack.empty() && stack.back().second > heights[i]) {
                auto [idx, height] = stack.back();
                stack.pop_back();
                int area = height * (i - idx);
                maxArea = max(maxArea, area);
                start = idx;
            }
            stack.emplace_back(start, heights[i]);
        }
        
        int n = heights.size();
        for (auto [idx, height] : stack) {
            int area = height * (n - idx);
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};