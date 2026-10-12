#include <vector>
using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for (int num = left; num <= right; ++num) {
            bool found = false;
            for (auto& range : ranges) {
                if (range[0] <= num && num <= range[1]) {
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }
};