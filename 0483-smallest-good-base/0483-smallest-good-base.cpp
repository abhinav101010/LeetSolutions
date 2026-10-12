class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stoll(n);
        int maxM = (int)(log2(num)) + 1;
        
        for (int m = maxM; m >= 2; m--) {
            long long k = pow(num, 1.0 / m);
            if (k <= 1) continue;
            long long total = (pow(k, m + 1) - 1) / (k - 1);
            if (total == num) {
                return to_string(k);
            }
        }
        
        return to_string(num - 1);
    }
    
private:
    long long pow(long long base, int exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result *= base;
            base *= base;
            exp >>= 1;
        }
        return result;
    }
};