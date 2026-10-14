#include <vector>
using namespace std;

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> res;
        vector<array<int,3>> squares; // left, right, height
        int curMax = 0;
        for (auto& pos : positions) {
            int left = pos[0];
            int side = pos[1];
            int right = left + side;
            int base = 0;
            for (auto& sq : squares) {
                int l = sq[0], r = sq[1], h = sq[2];
                if (!(r <= left || right <= l)) { // overlap
                    base = max(base, h);
                }
            }
            int h = base + side;
            squares.push_back({left, right, h});
            curMax = max(curMax, h);
            res.push_back(curMax);
        }
        return res;
    }
};
