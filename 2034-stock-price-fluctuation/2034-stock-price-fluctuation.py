class StockPrice:
    def __init__(self):
        self.d = {}
        self.ls = SortedList()
        self.last = 0

    def update(self, timestamp, price) :
        if timestamp in self.d:
            self.ls.remove(self.d[timestamp])
        self.d[timestamp] = price
        self.ls.add(price)
        self.last = max(self.last, timestamp)

    def current(self) :
        return self.d[self.last]

    def maximum(self) :
        return self.ls[-1]

    def minimum(self) :
        return self.ls[0]


# Your StockPrice object will be instantiated and called as such:
# obj = StockPrice()
# obj.update(timestamp,price)
# param_2 = obj.current()
# param_3 = obj.maximum()
# param_4 = obj.minimum()
