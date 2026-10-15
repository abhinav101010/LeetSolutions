class Solution:
    def minmaxGasDist(self, stations: list[int], k: int) -> float:
        def possible(D):
            count = 0
            for i in range(1, len(stations)):
                gap = stations[i] - stations[i-1]
                # number of stations needed to make max segment <= D
                # if gap <= D, need 0
                # else need ceil(gap / D) - 1
                import math
                count += math.ceil(gap / D) - 1
            return count <= k
        lo, hi = 0.0, float(stations[-1] - stations[0])
        for _ in range(100):
            mid = (lo + hi) / 2
            if possible(mid):
                hi = mid
            else:
                lo = mid
        return hi
