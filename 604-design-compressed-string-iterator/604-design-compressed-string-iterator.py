class StringIterator:

    def __init__(self, compressedString: str):
        self.s = compressedString
        self.i = 0  # index in s
        self.curr_char = ''
        self.curr_count = 0

    def next(self) -> str:
        if not self.hasNext():
            return ' '
        if self.curr_count == 0:
            # parse next char and count
            self.curr_char = self.s[self.i]
            self.i += 1
            start = self.i
            while self.i < len(self.s) and self.s[self.i].isdigit():
                self.i += 1
            self.curr_count = int(self.s[start:self.i])
        self.curr_count -= 1
        return self.curr_char

    def hasNext(self) -> bool:
        return self.i < len(self.s) or self.curr_count > 0
