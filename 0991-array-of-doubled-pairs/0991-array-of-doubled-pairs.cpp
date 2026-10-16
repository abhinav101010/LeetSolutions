#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> count;
        for (int x : arr) {
            count[x]++;
        }
        vector<int> keys;
        for (auto& p : count) {
            keys.push_back(p.first);
        }
        sort(keys.begin(), keys.end(), [](int a, int b) {
            int absA = abs(a), absB = abs(b);
            if (absA != absB) return absA < absB;
            return a < b;
        });
        for (int x : keys) {
            int c = count[x];
            if (c == 0) continue;
            int doubleX = 2 * x;
            if (count[doubleX] < c) {
                return false;
            }
            count[doubleX] -= c;
        }
        return true;
    }
};
