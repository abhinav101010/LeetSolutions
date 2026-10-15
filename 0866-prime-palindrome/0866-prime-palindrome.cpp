#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int primePalindrome(int n) {
        if (n <= 2) return 2;
        if (n == 3) return 3;
        if (n >= 8 && n <= 11) return 11;
        for (int length = 1; length <= 5; length++) {
            int start = (int) pow(10, length - 1);
            int end = (int) pow(10, length);
            for (int x = start; x < end; x++) {
                string s = to_string(x);
                string t = s;
                reverse(t.begin(), t.end());
                string pal_str = s + t.substr(1);
                int pal = stoi(pal_str);
                if (pal >= n && isPrime(pal)) {
                    return pal;
                }
            }
        }
        return -1;
    }
private:
    bool isPrime(int x) {
        if (x < 2) return false;
        if (x == 2) return true;
        if (x % 2 == 0) return false;
        for (int i = 3; i * i <= x; i += 2) {
            if (x % i == 0) return false;
        }
        return true;
    }
};
