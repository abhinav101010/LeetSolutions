#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

struct MyNumber {
    int num;
};

class Solution {
public:
    int biggestSingleNumber(vector<MyNumber> &numbers) {
        unordered_map<int, int> cnt;
        for (const auto &n : numbers) {
            cnt[n.num]++;
        }
        int res = -1;
        for (const auto &p : cnt) {
            if (p.second == 1) {
                if (p.first > res) res = p.first;
            }
        }
        return res;
    }
};
