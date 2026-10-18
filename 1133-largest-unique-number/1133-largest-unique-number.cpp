#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int x : nums) cnt[x]++;
        int ans = -1;
        for (auto& kv : cnt) {
            if (kv.second == 1 && kv.first > ans) ans = kv.first;
        }
        return ans;
    }
};