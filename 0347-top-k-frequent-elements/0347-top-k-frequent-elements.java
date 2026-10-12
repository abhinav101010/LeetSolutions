import java.util.*;

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int num : nums) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>(
            (a, b) -> count.get(a) - count.get(b)
        );

        for (int num : count.keySet()) {
            pq.offer(num);
            if (pq.size() > k) {
                pq.poll();
            }
        }

        int[] ans = new int[k];
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = pq.poll();
        }
        return ans;
    }
}