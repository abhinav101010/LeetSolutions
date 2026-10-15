#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        auto dist = [](const vector<int>& a, const vector<int>& b) {
            return abs(a[0]-b[0]) + abs(a[1]-b[1]);
        };
        int total = 0;
        int maxSave = 0;
        for (auto& nut : nuts) {
            int dTree = dist(tree, nut);
            total += 2 * dTree;
            int dSquirrel = dist(squirrel, nut);
            int save = dTree - dSquirrel;
            if (save > maxSave) {
                maxSave = save;
            }
        }
        return total - maxSave;
    }
};
