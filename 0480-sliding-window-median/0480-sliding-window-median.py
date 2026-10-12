from typing import List
import heapq

class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        max_heap = []  # max heap for smaller half
        min_heap = []  # min heap for larger half
        result = []
        
        def add(num):
            if not max_heap or num <= -max_heap[0]:
                heapq.heappush(max_heap, -num)
            else:
                heapq.heappush(min_heap, num)
        
        def remove(num):
            if num <= -max_heap[0]:
                max_heap.remove(-num)
                heapq.heapify(max_heap)
            else:
                min_heap.remove(num)
                heapq.heapify(min_heap)
        
        def balance():
            while len(max_heap) > len(min_heap) + 1:
                heapq.heappush(min_heap, -heapq.heappop(max_heap))
            while len(min_heap) > len(max_heap):
                heapq.heappush(max_heap, -heapq.heappop(min_heap))
        
        def get_median():
            if k % 2 == 1:
                return -max_heap[0]
            return (-max_heap[0] + min_heap[0]) / 2.0
        
        for i, num in enumerate(nums):
            add(num)
            balance()
            if i >= k:
                remove(nums[i - k])
                balance()
            if i >= k - 1:
                result.append(get_median())
        
        return result