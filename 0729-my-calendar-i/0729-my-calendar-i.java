import java.util.*;

class MyCalendar {
    private List<int[]> intervals;

    public MyCalendar() {
        intervals = new ArrayList<>();
    }

    public boolean book(int start, int end) {
        for (int[] iv : intervals) {
            int s = iv[0];
            int e = iv[1];
            if (!(end <= s || start >= e)) {
                return false;
            }
        }
        intervals.add(new int[]{start, end});
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */
