class Solution {
    public String minWindow(String S, String T) {
        int n = S.length();
        int m = T.length();
        if (m == 0) return "";
        int bestLen = Integer.MAX_VALUE;
        int bestStart = -1;
        int i = 0;
        while (i < n) {
            if (S.charAt(i) != T.charAt(0)) {
                i++;
                continue;
            }
            // forward match
            int j = i;
            int k = 0;
            while (j < n && k < m) {
                if (S.charAt(j) == T.charAt(k)) {
                    k++;
                }
                j++;
            }
            if (k != m) {
                // cannot complete T, break? Actually we can still move i forward.
                i++;
                continue;
            }
            int end = j - 1;
            // backward to tighten start
            int t = m - 1;
            int start = end;
            while (t >= 0) {
                if (S.charAt(start) == T.charAt(t)) {
                    t--;
                }
                start--;
            }
            start++; // because we went one extra
            int windowLen = end - start + 1;
            if (windowLen < bestLen || (windowLen == bestLen && start < bestStart)) {
                bestLen = windowLen;
                bestStart = start;
            }
            i = start + 1;
        }
        if (bestStart == -1) return "";
        return S.substring(bestStart, bestStart + bestLen);
    }
}
