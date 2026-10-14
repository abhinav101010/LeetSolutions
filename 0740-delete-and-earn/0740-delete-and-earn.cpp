#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxv = 0;
        for (int x : nums) {
            if (x > maxv) maxv = x;
        }
        vector<int> freq(maxv + 1, 0);
        for (int x : nums) {
            freq[x] += x;
        }
        int take = 0;
        int skip = 0;
        for (int v : freq) {
            int newTake = skip + v;
            int newSkip = max(take, skip);
            take = newTake;
            skip = newSkip;
        }
        return max(take, skip);
    }
};
