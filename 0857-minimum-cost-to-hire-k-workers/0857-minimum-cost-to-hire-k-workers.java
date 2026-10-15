import java.util.*;

class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        int n = quality.length;
        double[][] workers = new double[n][3];
        for (int i = 0; i < n; i++) {
            workers[i][0] = (double) wage[i] / quality[i]; // ratio
            workers[i][1] = quality[i];
            workers[i][2] = wage[i];
        }
        Arrays.sort(workers, (a, b) -> Double.compare(a[0], b[0]));
        // max-heap of quality (using PriorityQueue with reverse order)
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        int sumq = 0;
        double ans = Double.MAX_VALUE;
        for (double[] w : workers) {
            double ratio = w[0];
            int q = (int) w[1];
            maxHeap.offer(q);
            sumq += q;
            if (maxHeap.size() > k) {
                sumq -= maxHeap.poll();
            }
            if (maxHeap.size() == k) {
                ans = Math.min(ans, ratio * sumq);
            }
        }
        return ans;
    }
}
