class Solution {
public:
    int superPow(int a, vector<int>& b) {
        const int MOD = 1337;
        
        auto modPow = [&](int x, int y) {
            int result = 1;
            x %= MOD;
            while (y) {
                if (y & 1) result = (result * x) % MOD;
                x = (x * x) % MOD;
                y >>= 1;
            }
            return result;
        };
        
        int result = 1;
        for (int digit : b) {
            result = modPow(result, 10) * modPow(a, digit) % MOD;
        }
        return result;
    }
};