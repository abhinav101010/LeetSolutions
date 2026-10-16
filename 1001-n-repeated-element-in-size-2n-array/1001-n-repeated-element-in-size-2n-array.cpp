#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> seen;
        for (int x : nums) {
            if (seen.find(x) != seen.end()) {
                return x;
            }
            seen.insert(x);
        }
        return -1;
    }
};
