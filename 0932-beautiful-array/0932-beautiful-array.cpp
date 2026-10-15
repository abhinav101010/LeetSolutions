#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int N) {
        unordered_map<int, vector<int>> memo;
        memo[1] = {1};
        function<vector<int>(int)> solve = [&](int n) {
            if (memo.count(n)) return memo[n];
            vector<int> odds = solve((n + 1) / 2);
            vector<int> evens = solve(n / 2);
            vector<int> res;
            for (int x : odds) res.push_back(2 * x - 1);
            for (int x : evens) res.push_back(2 * x);
            memo[n] = res;
            return res;
        };
        return solve(N);
    }
};
