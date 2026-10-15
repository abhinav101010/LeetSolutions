import java.util.*;

class Solution {
    public int maxChunksToSorted(int[] arr) {
        int maxSeen = 0;
        int chunks = 0;
        for (int i = 0; i < arr.length; i++) {
            maxSeen = Math.max(maxSeen, arr[i]);
            if (maxSeen == i) {
                chunks++;
            }
        }
        return chunks;
    }
}
