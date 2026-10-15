#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int v : arr) cnt[v]++;
        vector<int> keys;
        for (auto& p : cnt) keys.push_back(p.first);
        sort(keys.begin(), keys.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        for (int x : keys) {
            if (cnt[x] > cnt[2*x]) {
                return false;
            }
            cnt[2*x] -= cnt[x];
        }
        return true;
    }
};
