#include <unordered_map>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        unordered_map<int, int> memo;
        this->x = x;
        return dfs(target);
    }
private:
    int x;
    unordered_map<int, int> memo;
    int dfs(int t) {
        if (t == 0) return 0;
        if (memo.count(t)) return memo[t];
        if (t < x) {
            int ans = min(2*t - 1, 2*(x - t));
            memo[t] = ans;
            return ans;
        }
        int k = (int)(log(t) / log(x));
        long p = 1;
        for (int i = 0; i < k; i++) p *= x;
        int ans1 = INT_MAX;
        if ((long)t >= p) {
            ans1 = k + dfs(t - (int)p);
        }
        long p2 = p * x;
        int ans2 = INT_MAX;
        if (p2 - t < t) {
            ans2 = (k+1) + dfs((int)(p2 - t));
        }
        int ans = min(ans1, ans2);
        memo[t] = ans;
        return ans;
    }
};
