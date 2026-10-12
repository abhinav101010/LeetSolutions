class Solution {
    public boolean hasAlternatingBits(int n) {
        String b = Integer.toBinaryString(n);
        char prev = ' ';
        for (int i = 0; i < b.length(); i++) {
            if (prev != ' ' && prev == b.charAt(i)) {
                return false;
            }
            prev = b.charAt(i);
        }
        return true;
    }
}
