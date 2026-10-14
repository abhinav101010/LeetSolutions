import java.util.*;

class MyCalendarTwo {
    private List<int[]> calendar;
    private List<int[]> overlap;

    public MyCalendarTwo() {
        calendar = new ArrayList<>();
        overlap = new ArrayList<>();
    }

    public boolean book(int start, int end) {
        // check triple booking
        for (int[] iv : overlap) {
            int s = iv[0];
            int e = iv[1];
            if (!(end <= s || start >= e)) {
                return false;
            }
        }
        List<int[]> newOverlaps = new ArrayList<>();
        for (int[] iv : calendar) {
            int s = iv[0];
            int e = iv[1];
            if (!(end <= s || start >= e)) {
                int sOverlap = Math.max(start, s);
                int eOverlap = Math.min(end, e);
                newOverlaps.add(new int[]{sOverlap, eOverlap});
            }
        }
        overlap.addAll(newOverlaps);
        calendar.add(new int[]{start, end});
        return true;
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(start,end);
 */
