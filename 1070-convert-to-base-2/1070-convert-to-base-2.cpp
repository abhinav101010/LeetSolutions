#include <string>
using namespace std;
class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        string s;
        while (n) {
            int r = n % 2;
            if (r < 0) r += 2;
            n = -(n / 2);
            s += char('0'+r);
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
