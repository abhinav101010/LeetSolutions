#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int top = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) top++;
            }
        }
        int front = 0;
        for (int i = 0; i < n; i++) {
            front += *max_element(grid[i].begin(), grid[i].end());
        }
        int side = 0;
        for (int j = 0; j < n; j++) {
            int maxCol = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] > maxCol) maxCol = grid[i][j];
            }
            side += maxCol;
        }
        return top + front + side;
    }
};
