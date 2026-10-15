#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isRationalEqual(string s, string t) {
        return toFraction(s) == toFraction(t);
    }
private:
    struct Fraction {
        __int128 num, den;
        Fraction(__int128 n, __int128 d) {
            __int128 g = gcd(n, d);
            num = n / g;
            den = d / g;
            if (den < 0) {
                num = -num;
                den = -den;
            }
        }
        bool operator==(const Fraction& other) const {
            return num == other.num && den == other.den;
        }
    };
    __int128 gcd(__int128 a, __int128 b) {
        while (b != 0) {
            __int128 t = b;
            b = a % b;
            a = t;
        }
        return a < 0 ? -a : a;
    }
    Fraction toFraction(const string& s) {
        if (s.find('(') == string::npos) {
            if (s.find('.') == string::npos) {
                return Fraction(stoi(s), 1);
            } else {
                size_t dot = s.find('.');
                string intPart = s.substr(0, dot);
                string fracPart = s.substr(dot+1);
                __int128 intBig = stoll(intPart);
                if (fracPart.empty()) {
                    return Fraction(intBig, 1);
                }
                __int128 tenPow = 1;
                for (int i = 0; i < fracPart.size(); i++) tenPow *= 10;
                __int128 fracBig = stoll(fracPart);
                __int128 num = intBig * tenPow + fracBig;
                return Fraction(num, tenPow);
            }
        } else {
            size_t dot = s.find('.');
            string intPart = s.substr(0, dot);
            string rest = s.substr(dot+1);
            size_t p = rest.find('(');
            string nonRep = rest.substr(0, p);
            string rep = rest.substr(p+1, rest.size()-p-2);
            int a = nonRep.size();
            int b = rep.size();
            __int128 I = stoll(intPart);
            __int128 N = nonRep.empty() ? 0 : stoll(nonRep);
            __int128 R = rep.empty() ? 0 : stoll(rep);
            __int128 pow10a = 1;
            for (int i = 0; i < a; i++) pow10a *= 10;
            __int128 pow10b = 1;
            for (int i = 0; i < b; i++) pow10b *= 10;
            __int128 denom = pow10a * (pow10b - 1);
            __int128 num = I * denom + N * (pow10b - 1) + R;
            return Fraction(num, denom);
        }
    }
};
