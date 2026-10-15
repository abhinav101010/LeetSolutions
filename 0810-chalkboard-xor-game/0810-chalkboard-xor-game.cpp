#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        if (nums.size() % 2 == 0) {
            return true;
        }
        int xr = 0;
        for (int v : nums) {
            xr ^= v;
        }
        return xr == 0;
    }
};
