import java.util.*;

class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] count = new int[26];
        for (char c : tasks) count[c - 'A']++;
        
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        for (int freq : count) if (freq > 0) maxHeap.offer(freq);
        
        int time = 0;
        Queue<int[]> waitQueue = new LinkedList<>();
        
        while (!maxHeap.isEmpty() || !waitQueue.isEmpty()) {
            time++;
            
            if (!maxHeap.isEmpty()) {
                int freq = maxHeap.poll() - 1;
                if (freq > 0) waitQueue.offer(new int[]{time + n, freq});
            }
            
            if (!waitQueue.isEmpty() && waitQueue.peek()[0] == time) {
                maxHeap.offer(waitQueue.poll()[1]);
            }
        }
        
        return time;
    }
}