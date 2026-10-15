#include <vector>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;
        for (int r = 0; r <= rows - 3; r++) {
            for (int c = 0; c <= cols - 3; c++) {
                if (magic(grid, r, c)) {
                    ans++;
                }
            }
        }
        return ans;
    }
private:
    bool magic(vector<vector<int>>& grid, int r, int c) {
        vector<bool> seen(10, false); // 1..9
        for (int i = r; i < r+3; i++) {
            for (int j = c; j < c+3; j++) {
                int val = grid[i][j];
                if (val < 1 || val > 9) return false;
                if (seen[val]) return false;
                seen[val] = true;
            }
        }
        int target = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        // rows
        for (int i = r; i < r+3; i++) {
            int sum = grid[i][c] + grid[i][c+1] + grid[i][c+2];
            if (sum != target) return false;
        }
        // cols
        for (int j = c; j < c+3; j++) {
            int sum = grid[r][j] + grid[r+1][j] + grid[r+2][j];
            if (sum != target) return false;
        }
        // diagonals
        if (grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != target) return false;
        if (grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != target) return false;
        return true;
    }
};
