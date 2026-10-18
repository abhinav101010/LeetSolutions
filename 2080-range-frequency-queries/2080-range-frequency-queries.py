class RangeFreqQuery:

    def __init__(self, arr):
        self.g = defaultdict(list)
        for i, x in enumerate(arr):
            self.g[x].append(i)

    def query(self, left, right, value) -> int:
        idx = self.g[value]
        l = bisect_left(idx, left)
        r = bisect_left(idx, right + 1)
        return r - l


# Your RangeFreqQuery object will be instantiated and called as such:
# obj = RangeFreqQuery(arr)
# param_1 = obj.query(left,right,value)
