#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
    vector<vector<vector<int>>> dp;
    vector<int> prefix;
    int k,n;
    int dfs(int i,int j,int m) {
        if (dp[i][j][m] != -1) return dp[i][j][m];
        if (i == j) return m == 1 ? 0 : 1000000005;
        if (m == 1) {
            int res = dfs(i,j,k) + (prefix[j+1] - prefix[i]);
            dp[i][j][m] = res;
            return res;
        }
        int res = 1000000005;
        for (int p = i; p < j; p += k-1) {
            res = min(res, dfs(i,p,1) + dfs(p+1,j,m-1));
        }
        dp[i][j][m] = res;
        return res;
    }
public:
    int mergeStones(vector<int>& stones, int k) {
        n = stones.size();
        this->k = k;
        if ((n-1)%(k-1) != 0) return -1;
        prefix.assign(n+1,0);
        for (int i=0;i<n;i++) prefix[i+1] = prefix[i] + stones[i];
        dp.assign(n, vector<vector<int>>(n, vector<int>(k+1, -1)));
        return dfs(0,n-1,1);
    }
};
