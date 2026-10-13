import java.util.*;

public class ZigzagIterator {
    private Queue<int[]> queue;
    
    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        queue = new LinkedList<>();
        if (!v1.isEmpty()) queue.add(new int[]{0, 0, v1.size()}); // index, list, size
        if (!v2.isEmpty()) queue.add(new int[]{0, 1, v2.size()});
        // store lists
        this.v1 = v1;
        this.v2 = v2;
    }
    
    private List<Integer> v1, v2;
    
    public int next() {
        int[] cur = queue.poll();
        int idx = cur[0];
        int listId = cur[1];
        int size = cur[2];
        int val = listId == 0 ? v1.get(idx) : v2.get(idx);
        if (idx + 1 < size) {
            queue.add(new int[]{idx + 1, listId, size});
        }
        return val;
    }
    
    public boolean hasNext() {
        return !queue.isEmpty();
    }
}