class SeatManager:
    def __init__(self, n):
        self.q = list(range(1, n + 1))

    def reserve(self):
        return heappop(self.q)

    def unreserve(self, seatNumber):
        heappush(self.q, seatNumber)


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)
