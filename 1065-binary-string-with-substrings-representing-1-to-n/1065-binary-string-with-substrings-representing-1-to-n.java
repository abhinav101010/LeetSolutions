class Solution {
    public boolean queryString(String s, int n) {
        for (int i = 1; i <= n; i++) {
            String binI = Integer.toBinaryString(i);
            if (!s.contains(binI)) return false;
        }
        return true;
    }
}
