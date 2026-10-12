import heapq
from collections import Counter
from typing import List

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        count = Counter(tasks)
        max_heap = [-freq for freq in count.values()]
        heapq.heapify(max_heap)
        
        time = 0
        wait_queue = []  # (available_time, freq)
        
        while max_heap or wait_queue:
            time += 1
            
            if max_heap:
                freq = 1 + heapq.heappop(max_heap)
                if freq < 0:
                    wait_queue.append((time + n, freq))
            
            if wait_queue and wait_queue[0][0] == time:
                _, freq = wait_queue.pop(0)
                heapq.heappush(max_heap, freq)
        
        return time