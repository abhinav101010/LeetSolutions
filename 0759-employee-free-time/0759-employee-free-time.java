import java.util.*;

// Definition for an Interval.
class Interval {
    public int start;
    public int end;
    public Interval() {}
    public Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
}

class Solution {
    public List<Interval> employeeFreeTime(List<List<Interval>> schedule) {
        List<int[]> intervals = new ArrayList<>();
        for (List<Interval> emp : schedule) {
            for (Interval iv : emp) {
                intervals.add(new int[]{iv.start, iv.end});
            }
        }
        if (intervals.isEmpty()) return new ArrayList<>();
        intervals.sort(Comparator.comparingInt(a -> a[0]));
        List<int[]> merged = new ArrayList<>();
        int[] cur = intervals.get(0);
        for (int i = 1; i < intervals.size(); i++) {
            int[] nxt = intervals.get(i);
            if (nxt[0] <= cur[1]) {
                cur[1] = Math.max(cur[1], nxt[1]);
            } else {
                merged.add(cur);
                cur = nxt;
            }
        }
        merged.add(cur);
        List<Interval> free = new ArrayList<>();
        for (int i = 1; i < merged.size(); i++) {
            int[] prev = merged.get(i-1);
            int[] curr = merged.get(i);
            if (prev[1] < curr[0]) {
                free.add(new Interval(prev[1], curr[0]));
            }
        }
        return free;
    }
}
