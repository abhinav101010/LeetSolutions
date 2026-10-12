class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int totalItems = rows * cols;

        k %= totalItems;
        if (k == 0) {
            return grid;
        }

        vector<int> flat;
        for (auto& row : grid) {
            flat.insert(flat.end(), row.begin(), row.end());
        }

        vector<int> newGrid = flat;
        newGrid.insert(newGrid.end(), flat.begin(), flat.end());

        int startPoint = totalItems - k;

        vector<vector<int>> ans;
        vector<int> curr;

        for (int i = startPoint; i < startPoint + totalItems; i++) {
            curr.push_back(newGrid[i]);
            if (curr.size() == cols) {
                ans.push_back(curr);
                curr.clear();
            }
        }

        return ans;
    }
};