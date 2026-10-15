class RLEIterator:
    def __init__(self, encoding: list[int]):
        self.encoding = encoding
        self.i = 0          # index in encoding (points to frequency)
        self.remaining = 0  # remaining count of current value

    def next(self, n: int) -> int:
        while self.i < len(self.encoding):
            if self.remaining == 0:
                self.remaining = self.encoding[self.i]
                if self.remaining == 0:
                    self.i += 2
                    continue
            if self.remaining >= n:
                self.remaining -= n
                return self.encoding[self.i+1]
            else:
                n -= self.remaining
                self.remaining = 0
                self.i += 2
        return -1
