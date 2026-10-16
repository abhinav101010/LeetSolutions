class StringIterator:
    def __init__(self, compressedString):
        self.s = compressedString
        self.i = 0
        self.cnt = 0
        self.ch = ''
    def next(self):
        if self.hasNext():
            self.cnt -= 1
            return self.ch
        return ' '
    def hasNext(self):
        if self.cnt > 0:
            return True
        if self.i >= len(self.s):
            return False
        self.ch = self.s[self.i]
        self.i += 1
        j = self.i
        while j < len(self.s) and self.s[j].isdigit():
            j += 1
        self.cnt = int(self.s[self.i:j])
        self.i = j
        return True
