class Solution {
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

public:
    string fractionAddition(string expression) {
        long num = 0, den = 1;
        int i = 0, n = expression.size();
        
        while (i < n) {
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                sign = expression[i] == '+' ? 1 : -1;
                i++;
            }
            
            long a = 0;
            while (i < n && isdigit(expression[i])) {
                a = a * 10 + (expression[i] - '0');
                i++;
            }
            a *= sign;
            
            if (i >= n || expression[i] != '/') return "";
            i++;
            
            long b = 0;
            while (i < n && isdigit(expression[i])) {
                b = b * 10 + (expression[i] - '0');
                i++;
            }
            
            num = num * b + a * den;
            den = den * b;
            long g = gcd(abs(num), den);
            num /= g;
            den /= g;
        }
        
        return to_string(num) + "/" + to_string(den);
    }
};