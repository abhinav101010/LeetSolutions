import bisect

class ExamRoom:
    def __init__(self, n: int):
        self.n = n
        self.seats = []  # sorted list of occupied seats

    def seat(self) -> int:
        if not self.seats:
            pos = 0
        else:
            # consider first seat
            max_dist = self.seats[0]
            pos = 0
            # consider intervals between seats
            for i in range(len(self.seats)-1):
                a, b = self.seats[i], self.seats[i+1]
                dist = (b - a) // 2
                if dist > max_dist:
                    max_dist = dist
                    pos = a + dist
            # consider last seat
            dist_last = self.n - 1 - self.seats[-1]
            if dist_last > max_dist:
                max_dist = dist_last
                pos = self.n - 1
        bisect.insort(self.seats, pos)
        return pos

    def leave(self, p: int) -> None:
        i = bisect.bisect_left(self.seats, p)
        self.seats.pop(i)
