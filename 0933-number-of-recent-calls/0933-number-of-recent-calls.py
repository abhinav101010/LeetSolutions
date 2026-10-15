class RecentCounter:
    def __init__(self):
        from collections import deque
        self.q = deque()
    def ping(self, t: int) -> int:
        self.q.append(t)
        while self.q[0] < t - 3000:
            self.q.popleft()
        return len(self.q)
