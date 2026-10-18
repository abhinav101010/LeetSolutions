class Solution {
    public int longestDecomposition(String text) {
        int n = text.length();
        int ans = 0;
        int i = 0, j = n - 1;
        while (i <= j) {
            int k = 1;
            boolean ok = false;
            while (i + k - 1 < j - k + 1) {
                if (text.substring(i, i + k).equals(text.substring(j - k + 1, j + 1))) {
                    ans += 2;
                    i += k;
                    j -= k;
                    ok = true;
                    break;
                }
                k++;
            }
            if (!ok) {
                ans++;
                break;
            }
        }
        return ans;
    }
}
