import java.util.*;
class Solution {
    public int videoStitching(int[][] clips, int T) {
        Arrays.sort(clips, (a,b) -> Integer.compare(a[0], b[0]));
        int res = 0, currEnd = 0, nextEnd = 0, i = 0;
        int n = clips.length;
        while (currEnd < T) {
            while (i < n && clips[i][0] <= currEnd) {
                nextEnd = Math.max(nextEnd, clips[i][1]);
                i++;
            }
            if (nextEnd == currEnd) return -1;
            currEnd = nextEnd;
            res++;
        }
        return res;
    }
}
