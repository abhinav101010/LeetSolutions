class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        import math
        w = int(math.sqrt(area))
        while area % w != 0:
            w -= 1
        return [area // w, w]