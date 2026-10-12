class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0;
        long right = (long)sqrt(c);
        
        while (left <= right) {
            long s = left * left + right * right;
            if (s == c) return true;
            if (s < c) left++;
            else right--;
        }
        
        return false;
    }
};