class Query:
    def __init__(self, query_name, result, position, rating):
        self.query_name = query_name
        self.result = result
        self.position = position
        self.rating = rating

class Solution:
    def queriesQualityAndPercentage(self, queries):
        byName = {}
        for q in queries:
            byName.setdefault(q.query_name, []).append(q)
        ans = []
        for name, qs in byName.items():
            n = len(qs)
            quality = 0.0
            poor = 0.0
            for q in qs:
                quality += q.rating / q.position
                if q.rating < 3:
                    poor += 1.0
            quality /= n
            poor = poor / n * 100.0
            ans.append([name, f"{quality:.2f}", f"{poor:.2f}"])
        return ans
