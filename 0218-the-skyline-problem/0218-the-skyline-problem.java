import java.util.*;

class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        List<int[]> events = new ArrayList<>();
        for (int[] b : buildings) {
            events.add(new int[]{b[0], -b[2], b[1]});  // Start
            events.add(new int[]{b[1], b[2], 0});      // End
        }
        
        events.sort((a, b) -> {
            if (a[0] != b[0]) return a[0] - b[0];
            return a[1] - b[1];
        });
        
        List<List<Integer>> result = new ArrayList<>();
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]); // (height, end)
        pq.offer(new int[]{0, Integer.MAX_VALUE});
        
        for (int[] e : events) {
            int x = e[0], h = e[1], r = e[2];
            if (h < 0) {
                pq.offer(new int[]{h, r});
            } else {
                while (!pq.isEmpty() && pq.peek()[1] <= x) {
                    pq.poll();
                }
            }
            
            int maxH = -pq.peek()[0];
            if (result.isEmpty() || result.get(result.size() - 1).get(1) != maxH) {
                result.add(Arrays.asList(x, maxH));
            }
        }
        
        return result;
    }
}