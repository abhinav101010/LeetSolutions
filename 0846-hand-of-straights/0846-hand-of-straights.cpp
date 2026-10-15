#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (hand.size() % W != 0) return false;
        map<int, int> cnt;
        for (int card : hand) {
            cnt[card]++;
        }
        while (!cnt.empty()) {
            int first = cnt.begin()->first;
            int count = cnt.begin()->second;
            for (int i = 0; i < W; i++) {
                int cur = first + i;
                if (cnt.find(cur) == cnt.end() || cnt[cur] < count) {
                    return false;
                }
                cnt[cur] -= count;
                if (cnt[cur] == 0) {
                    cnt.erase(cur);
                }
            }
        }
        return true;
    }
};
