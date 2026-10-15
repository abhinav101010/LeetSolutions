class FreqStack:
    def __init__(self):
        self.freq = {}          # value -> frequency
        self.group = {}         # frequency -> stack of values
        self.maxfreq = 0

    def push(self, x: int) -> None:
        f = self.freq.get(x, 0) + 1
        self.freq[x] = f
        if f > self.maxfreq:
            self.maxfreq = f
        if f not in self.group:
            self.group[f] = []
        self.group[f].append(x)

    def pop(self) -> int:
        x = self.group[self.maxfreq].pop()
        self.freq[x] -= 1
        if not self.group[self.maxfreq]:
            self.maxfreq -= 1
        return x
