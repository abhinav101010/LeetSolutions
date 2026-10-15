#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int total = R * C;
        vector<vector<int>> res;
        res.push_back({r0, c0});
        if (total == 1) return res;
        // directions: east, south, west, north
        vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        int dirIdx = 0;
        int step = 1;
        int r = r0, c = c0;
        while ((int)res.size() < total) {
            for (int k = 0; k < 2; k++) {
                int dr = dirs[dirIdx].first;
                int dc = dirs[dirIdx].second;
                for (int s = 0; s < step; s++) {
                    r += dr;
                    c += dc;
                    if (r >= 0 && r < R && c >= 0 && c < C) {
                        res.push_back({r, c});
                        if ((int)res.size() == total) return res;
                    }
                }
                dirIdx = (dirIdx + 1) % 4;
            }
            step++;
        }
        return res;
    }
};
