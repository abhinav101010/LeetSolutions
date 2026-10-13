#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long prev = (long)lower - 1;
        for (int i = 0; i <= nums.size(); i++) {
            long cur = i < nums.size() ? (long)nums[i] : (long)upper + 1;
            if (cur > prev + 1) {
                long l = prev + 1;
                long r = cur - 1;
                if (l == r) {
                    res.push_back(to_string(l));
                } else {
                    res.push_back(to_string(l) + "->" + to_string(r));
                }
            }
            prev = cur;
        }
        return res;
    }
};