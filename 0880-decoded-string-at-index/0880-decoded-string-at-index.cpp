#include <string>
using namespace std;

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long length = 0;
        for (char ch : s) {
            if (isdigit(ch)) {
                length *= (ch - '0');
            } else {
                length++;
            }
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            char ch = s[i];
            if (k % length == 0 && isalpha(ch)) {
                return string(1, ch);
            }
            if (isdigit(ch)) {
                length /= (ch - '0');
            } else {
                length--;
            }
        }
        return "";
    }
};
