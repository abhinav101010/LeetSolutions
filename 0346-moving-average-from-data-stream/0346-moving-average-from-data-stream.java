import java.util.*;

class MovingAverage {
    private Queue<Integer> q;
    private int size;
    private long sum;
    
    public MovingAverage(int size) {
        q = new LinkedList<>();
        this.size = size;
        sum = 0;
    }
    
    public double next(int val) {
        if (q.size() == size) {
            sum -= q.poll();
        }
        q.offer(val);
        sum += val;
        return (double)sum / q.size();
    }
}