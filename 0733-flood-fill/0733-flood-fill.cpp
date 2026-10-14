#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size();
        int cols = image[0].size();
        int orig = image[sr][sc];
        if (orig == newColor) {
            return image;
        }
        dfs(image, sr, sc, orig, newColor, rows, cols);
        return image;
    }
    
private:
    void dfs(vector<vector<int>>& image, int r, int c, int orig, int newColor, int rows, int cols) {
        if (image[r][c] != orig) {
            return;
        }
        image[r][c] = newColor;
        if (r > 0) dfs(image, r-1, c, orig, newColor, rows, cols);
        if (r+1 < rows) dfs(image, r+1, c, orig, newColor, rows, cols);
        if (c > 0) dfs(image, r, c-1, orig, newColor, rows, cols);
        if (c+1 < cols) dfs(image, r, c+1, orig, newColor, rows, cols);
    }
};
