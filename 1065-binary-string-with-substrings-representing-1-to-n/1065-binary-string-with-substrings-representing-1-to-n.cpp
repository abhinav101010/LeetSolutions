#include <string>
using namespace std;
class Solution {
public:
    bool queryString(string s, int n) {
        for (int i = 1; i <= n; i++) {
            string binI = "";
            int num = i;
            while (num > 0) {
                binI = char('0' + num % 2) + binI;
                num /= 2;
            }
            if (s.find(binI) == string::npos) return false;
        }
        return true;
    }
};
