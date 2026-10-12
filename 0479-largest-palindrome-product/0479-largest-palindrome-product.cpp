class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        int upper = pow(10, n) - 1;
        int lower = pow(10, n - 1);
        for (int i = upper; i >= lower; i--) {
            string s = to_string(i);
            string rev = s;
            reverse(rev.begin(), rev.end());
            long long pal = stoll(s + rev);
            for (int j = upper; j >= (int)sqrt(pal); j--) {
                if (pal % j == 0 && pal / j >= lower && pal / j <= upper) {
                    return pal % 1337;
                }
            }
        }
        return 0;
    }
};