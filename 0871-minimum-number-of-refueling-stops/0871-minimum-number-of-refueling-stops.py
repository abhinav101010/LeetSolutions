import heapq

class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: list[list[int]]) -> int:
        # max-heap (store negative for min-heap in Python)
        maxheap = []
        i = 0
        n = len(stations)
        fuel = startFuel
        stops = 0
        while fuel < target:
            while i < n and stations[i][0] <= fuel:
                heapq.heappush(maxheap, -stations[i][1])
                i += 1
            if not maxheap:
                return -1
            fuel += -heapq.heappop(maxheap)
            stops += 1
        return stops
