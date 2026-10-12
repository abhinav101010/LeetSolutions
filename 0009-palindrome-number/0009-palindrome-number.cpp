class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long rest = x;
        long reversed = 0;

        while (rest > 0) {
            reversed = reversed * 10 + rest % 10;
            rest /= 10;
        }

        return reversed == x;
    }
};
