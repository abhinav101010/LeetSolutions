#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0;
        int bestI = values[0] + 0;
        for (int j = 1; j < values.size(); j++) {
            res = max(res, bestI + values[j] - j);
            bestI = max(bestI, values[j] + j);
        }
        return res;
    }
};
