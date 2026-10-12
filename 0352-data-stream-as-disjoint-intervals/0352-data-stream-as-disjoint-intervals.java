import java.util.*;

class SummaryRanges {
    private List<int[]> intervals;
    
    public SummaryRanges() {
        intervals = new ArrayList<>();
    }
    
    public void addNum(int value) {
        int left = 0, right = intervals.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (intervals.get(mid)[0] < value) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if (left > 0 && intervals.get(left - 1)[1] + 1 >= value) {
            left--;
        }
        
        int newStart = value, newEnd = value;
        while (left < intervals.size() && intervals.get(left)[0] <= newEnd + 1) {
            newStart = Math.min(newStart, intervals.get(left)[0]);
            newEnd = Math.max(newEnd, intervals.get(left)[1]);
            intervals.remove(left);
        }
        
        intervals.add(left, new int[]{newStart, newEnd});
    }
    
    public int[][] getIntervals() {
        return intervals.toArray(new int[0][]);
    }
}