#include <vector>
#include <map>
#include <functional>
using namespace std;

class Solution {
public:
    double soupServings(int n) {
        if (n >= 4800) {
            return 1.0;
        }
        map<pair<int,int>, double> memo;
        return dp(n, n, memo);
    }
private:
    double dp(int a, int b, map<pair<int,int>, double>& memo) {
        if (a <= 0 && b <= 0) {
            return 0.5;
        }
        if (a <= 0) {
            return 1.0;
        }
        if (b <= 0) {
            return 0.0;
        }
        pair<int,int> key = {a, b};
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        double res = 0.25 * (
            dp(a-100, b, memo) +
            dp(a-75, b-25, memo) +
            dp(a-50, b-50, memo) +
            dp(a-25, b-75, memo)
        );
        memo[key] = res;
        return res;
    }
};
