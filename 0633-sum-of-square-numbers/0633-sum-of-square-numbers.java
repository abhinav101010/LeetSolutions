class Solution {
    public boolean judgeSquareSum(int c) {
        long left = 0;
        long right = (long)Math.sqrt(c);
        
        while (left <= right) {
            long s = left * left + right * right;
            if (s == c) return true;
            if (s < c) left++;
            else right--;
        }
        
        return false;
    }
}