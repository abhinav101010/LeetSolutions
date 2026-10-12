import java.util.*;

class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        Arrays.sort(envelopes, (a, b) -> {
            if (a[0] != b[0]) return a[0] - b[0];
            return b[1] - a[1];
        });
        
        List<Integer> tails = new ArrayList<>();
        for (int[] e : envelopes) {
            int h = e[1];
            int idx = Collections.binarySearch(tails, h);
            if (idx < 0) idx = -(idx + 1);
            if (idx == tails.size()) {
                tails.add(h);
            } else {
                tails.set(idx, h);
            }
        }
        return tails.size();
    }
}