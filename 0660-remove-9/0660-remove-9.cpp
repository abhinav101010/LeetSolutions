class Solution {
public:
    int newInteger(int n) {
        int res = 0;
        int place = 1;
        while (n > 0) {
            int digit = n % 9;
            res += digit * place;
            place *= 10;
            n /= 9;
        }
        return res;
    }
};
