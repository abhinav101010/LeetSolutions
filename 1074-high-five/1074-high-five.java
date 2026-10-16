import java.util.*;
class Solution {
    public List<List<Integer>> highFive(int[][] items) {
        Map<Integer, PriorityQueue<Integer>> scores = new TreeMap<>();
        for (int[] item : items) {
            scores.computeIfAbsent(item[0], k -> new PriorityQueue<>(Collections.reverseOrder())).add(item[1]);
        }
        List<List<Integer>> res = new ArrayList<>();
        for (Map.Entry<Integer, PriorityQueue<Integer>> e : scores.entrySet()) {
            PriorityQueue<Integer> pq = e.getValue();
            int sum = 0;
            for (int k = 0; k < 5; k++) sum += pq.poll();
            res.add(Arrays.asList(e.getKey(), sum/5));
        }
        return res;
    }
}
