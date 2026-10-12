class Solution:
    def nearestValidPoint(self, x: int, y: int, points: list[list[int]]) -> int:
        min_distance = float('inf')
        answer = -1

        for i, (px, py) in enumerate(points):

            # Check if the point is valid
            if px == x or py == y:

                distance = abs(x - px) + abs(y - py)

                if distance < min_distance:
                    min_distance = distance
                    answer = i

        return answer