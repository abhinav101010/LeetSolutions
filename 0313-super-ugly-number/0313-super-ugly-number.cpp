class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n);
        ugly[0] = 1;
        vector<int> idx(primes.size(), 0);
        vector<int> val = primes;
        
        for (int i = 1; i < n; i++) {
            int nextUgly = val[0];
            for (int v : val) nextUgly = min(nextUgly, v);
            ugly[i] = nextUgly;
            
            for (int j = 0; j < (int)primes.size(); j++) {
                if (val[j] == nextUgly) {
                    idx[j]++;
                    val[j] = ugly[idx[j]] * primes[j];
                }
            }
        }
        
        return ugly[n - 1];
    }
};