class Solution {
    public int getSum(int a, int b) {
        int mask = 0xFFFFFFFF;

        a = a & mask;
        b = b & mask;

        while (b != 0) {
            int carry = (a & b) << 1;

            a = (a ^ b) & mask;
            b = carry & mask;
        }

        if ((a & 0x80000000) != 0) {
            a = ~(a ^ mask);
        }

        return a;
    }
}