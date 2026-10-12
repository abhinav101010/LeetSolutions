#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count, tails;
        for (int n : nums) count[n]++;
        
        for (int n : nums) {
            if (count[n] == 0) continue;
            if (tails[n - 1] > 0) {
                tails[n - 1]--;
                tails[n]++;
            } else if (count[n + 1] > 0 && count[n + 2] > 0) {
                count[n + 1]--;
                count[n + 2]--;
                tails[n + 2]++;
            } else {
                return false;
            }
            count[n]--;
        }
        return true;
    }
};