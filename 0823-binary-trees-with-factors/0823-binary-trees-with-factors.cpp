#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1000000007;
        sort(arr.begin(), arr.end());
        unordered_map<int, long> dp;
        for (int x : arr) {
            dp[x] = 1;
        }
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    int right = arr[i] / arr[j];
                    if (dp.find(right) != dp.end()) {
                        long val = (dp[arr[i]] + dp[arr[j]] * dp[right]) % MOD;
                        dp[arr[i]] = val;
                    }
                }
            }
        }
        long ans = 0;
        for (auto& p : dp) {
            ans = (ans + p.second) % MOD;
        }
        return (int) ans;
    }
};
