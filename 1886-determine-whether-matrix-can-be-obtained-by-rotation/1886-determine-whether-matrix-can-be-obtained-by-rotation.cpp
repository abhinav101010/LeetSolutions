#include <vector>
using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int r = 0; r < 4; ++r) {
            if (mat == target) return true;
            mat = rotate(mat);
        }
        return false;
    }
    
private:
    vector<vector<int>> rotate(const vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> rotated(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rotated[j][n - 1 - i] = mat[i][j];
            }
        }
        return rotated;
    }
};