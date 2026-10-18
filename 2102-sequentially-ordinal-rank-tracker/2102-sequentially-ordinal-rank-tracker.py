class SORTracker:
    def __init__(self):
        self.sl = SortedList()
        self.i = -1

    def add(self, name, score) :
        self.sl.add((-score, name))

    def get(self) :
        self.i += 1
        return self.sl[self.i][1]


# Your SORTracker object will be instantiated and called as such:
# obj = SORTracker()
# obj.add(name,score)
# param_2 = obj.get()
