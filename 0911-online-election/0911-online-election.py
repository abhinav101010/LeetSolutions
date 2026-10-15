class TopVotedAce:
    def __init__(self, persons: list[int], times: list[int]):
        self.times = times
        self.leaders = []
        count = {}
        leader = -1
        maxvotes = 0
        for p, t in zip(persons, times):
            count[p] = count.get(p, 0) + 1
            if count[p] >= maxvotes:
                maxvotes = count[p]
                leader = p
            self.leaders.append(leader)

    def q(self, t: int) -> int:
        # binary search rightmost index where times[idx] <= t
        import bisect
        idx = bisect.bisect_right(self.times, t) - 1
        return self.leaders[idx]
