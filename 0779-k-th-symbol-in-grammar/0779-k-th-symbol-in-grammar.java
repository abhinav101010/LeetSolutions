class Solution {
    public int kthGrammar(int n, int k) {
        int bits = Integer.bitCount(k-1);
        return bits % 2;
    }
}
