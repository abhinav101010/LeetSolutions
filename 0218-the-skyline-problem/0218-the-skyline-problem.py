from typing import List
import heapq

class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        events = []
        for left, right, height in buildings:
            events.append((left, -height, right))   # Start: negative height
            events.append((right, height, 0))       # End: positive height
        
        events.sort()
        
        result = []
        heap = [(0, float('inf'))]  # (height, end)
        
        for x, h, r in events:
            if h < 0:  # Start
                heapq.heappush(heap, (h, r))
            else:      # End
                # Remove ended buildings
                while heap and heap[0][1] <= x:
                    heapq.heappop(heap)
            
            max_h = -heap[0][0]
            if not result or result[-1][1] != max_h:
                result.append([x, max_h])
        
        return result