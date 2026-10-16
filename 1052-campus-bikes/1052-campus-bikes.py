import heapq
class Solution:
    def assignBikes(self, workers, bikes):
        n = len(workers)
        m = len(bikes)
        pairs = []
        for i in range(n):
            x1,y1 = workers[i]
            for j in range(m):
                x2,y2 = bikes[j]
                d = abs(x1-x2)+abs(y1-y2)
                pairs.append((d,i,j))
        pairs.sort()
        res = [ -1 ] * n
        used_bikes = set()
        for d,i,j in pairs:
            if res[i] == -1 and j not in used_bikes:
                res[i] = j
                used_bikes.add(j)
            if len(used_bikes) == n: break
        return res
