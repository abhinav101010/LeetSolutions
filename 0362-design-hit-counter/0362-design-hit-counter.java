import java.util.*;

class HitCounter {
    private Queue<Integer> q;
    
    public HitCounter() {
        q = new LinkedList<>();
    }
    
    public void hit(int timestamp) {
        q.offer(timestamp);
    }
    
    public int getHits(int timestamp) {
        while (!q.isEmpty() && q.peek() <= timestamp - 300) {
            q.poll();
        }
        return q.size();
    }
}