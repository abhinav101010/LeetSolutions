#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int total = 0;
        int maxDist = -1;
        for (const auto &nut : nuts) {
            int d = abs(tree[0] - nut[0]) + abs(tree[1] - nut[1]);
            total += 2 * d;
            int d2 = abs(squirrel[0] - nut[0]) + abs(squirrel[1] - nut[1]);
            maxDist = max(maxDist, d - d2);
        }
        return total - maxDist;
    }
};
