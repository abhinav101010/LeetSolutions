class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        long long num = (long long) numerator;
        long long den = (long long) denominator;
        string ans;
        if ((num < 0) ^ (den < 0)) ans += '-';
        num = llabs(num);
        den = llabs(den);
        ans += to_string(num / den);
        long long rem = num % den;
        if (rem == 0) return ans;
        ans += '.';
        unordered_map<long long, int> seen;
        while (rem) {
            if (seen.count(rem)) {
                ans.insert(seen[rem], "(");
                ans += ')';
                break;
            }
            seen[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / den);
            rem %= den;
        }
        return ans;
    }
};