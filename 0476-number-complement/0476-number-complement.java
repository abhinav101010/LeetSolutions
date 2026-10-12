class Solution {
    public int findComplement(int num) {
        int mask = (1 << (32 - Integer.numberOfLeadingZeros(num))) - 1;
        return num ^ mask;
    }
}