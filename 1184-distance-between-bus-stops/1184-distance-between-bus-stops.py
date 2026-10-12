class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        total = sum(distance)

        curr = 0
        n = len(distance)

        while start != destination:
            curr += distance[start]
            start = (start + 1) % n

        return min(curr, total - curr)