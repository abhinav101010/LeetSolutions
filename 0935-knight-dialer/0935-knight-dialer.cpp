#include <vector>
using namespace std;

class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> moves = {
            {4,6}, //0
            {6,8}, //1
            {7,9}, //2
            {4,8}, //3
            {0,3,9}, //4
            {}, //5
            {0,1,7}, //6
            {2,6}, //7
            {1,3}, //8
            {2,4} //9
        };
        const int MOD = 1000000007;
        vector<long> dp(10, 1);
        for (int step = 1; step < n; step++) {
            vector<long> dp2(10, 0);
            for (int d = 0; d < 10; d++) {
                for (int nxt : moves[d]) {
                    dp2[nxt] = (dp2[nxt] + dp[d]) % MOD;
                }
            }
            dp = move(dp2);
        }
        long sum = 0;
        for (long v : dp) sum = (sum + v) % MOD;
        return (int) sum;
    }
};
