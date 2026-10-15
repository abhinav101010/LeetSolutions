#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        long long L = stoll(left);
        long long R = stoll(right);
        int count = 0;
        for (long long k = 1; k < 10000; k++) {
            string s = to_string(k);
            // odd length palindrome
            string odd = s;
            string rev = s;
            reverse(rev.begin(), rev.end());
            odd += rev.substr(1);
            long long p_odd = stoll(odd);
            long long square = p_odd * p_odd;
            if (square <= R && square >= L && isPalindrome(square)) {
                count++;
            }
            // even length palindrome
            string even = s;
            even += rev;
            long long p_even = stoll(even);
            square = p_even * p_even;
            if (square <= R && square >= L && isPalindrome(square)) {
                count++;
            }
        }
        return count;
    }
private:
    bool isPalindrome(long long x) {
        string s = to_string(x);
        int i = 0, j = (int)s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
};
