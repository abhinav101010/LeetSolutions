#include <vector>
using namespace std;
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> c(60,0);
        int ans = 0;
        for (int t : time) {
            int rem = t % 60;
            ans += c[(60 - rem) % 60];
            c[rem]++;
        }
        return ans;
    }
};
