class Solution {
    public int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        int remainder = 0;
        int length = 1;
        while (true) {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0) return length;
            length++;
        }
    }
}
