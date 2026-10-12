import java.util.*;

class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        double[] result = new double[nums.length - k + 1];
        
        for (int i = 0; i < nums.length; i++) {
            addNum(nums[i], maxHeap, minHeap);
            balanceHeaps(maxHeap, minHeap);
            
            if (i >= k) {
                removeNum(nums[i - k], maxHeap, minHeap);
                balanceHeaps(maxHeap, minHeap);
            }
            
            if (i >= k - 1) {
                result[i - k + 1] = getMedian(maxHeap, minHeap, k);
            }
        }
        
        return result;
    }
    
    private void addNum(int num, PriorityQueue<Integer> maxHeap, PriorityQueue<Integer> minHeap) {
        if (maxHeap.isEmpty() || num <= maxHeap.peek()) {
            maxHeap.offer(num);
        } else {
            minHeap.offer(num);
        }
    }
    
    private void removeNum(int num, PriorityQueue<Integer> maxHeap, PriorityQueue<Integer> minHeap) {
        if (num <= maxHeap.peek()) {
            maxHeap.remove(num);
        } else {
            minHeap.remove(num);
        }
    }
    
    private void balanceHeaps(PriorityQueue<Integer> maxHeap, PriorityQueue<Integer> minHeap) {
        while (maxHeap.size() > minHeap.size() + 1) {
            minHeap.offer(maxHeap.poll());
        }
        while (minHeap.size() > maxHeap.size()) {
            maxHeap.offer(minHeap.poll());
        }
    }
    
    private double getMedian(PriorityQueue<Integer> maxHeap, PriorityQueue<Integer> minHeap, int k) {
        if (k % 2 == 1) return maxHeap.peek();
        return ((double)maxHeap.peek() + minHeap.peek()) / 2.0;
    }
}