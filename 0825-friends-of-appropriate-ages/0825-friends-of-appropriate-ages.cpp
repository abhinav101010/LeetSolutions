#include <vector>
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> cnt(121,0);
        for (int age : ages) cnt[age]++;
        int ans = 0;
        for (int ageA = 0; ageA <= 120; ++ageA) {
            if (cnt[ageA] == 0) continue;
            for (int ageB = 0; ageB <= 120; ++ageB) {
                if (cnt[ageB] == 0) continue;
                if (ageB <= 0.5 * ageA + 7) continue;
                if (ageB > ageA) continue;
                if (ageB > 100 && ageA < 100) continue;
                if (ageA == ageB) {
                    ans += cnt[ageA] * (cnt[ageA] - 1);
                } else {
                    ans += cnt[ageA] * cnt[ageB];
                }
            }
        }
        return ans;
    }
};
