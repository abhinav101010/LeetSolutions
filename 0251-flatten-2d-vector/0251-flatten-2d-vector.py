from typing import List

class Vector2D:
    def __init__(self, vec: List[List[int]]):
        self.vec = vec
        self.i = 0
        self.j = 0
    
    def next(self) -> int:
        self._advance()
        val = self.vec[self.i][self.j]
        self.j += 1
        return val
    
    def hasNext(self) -> bool:
        self._advance()
        return self.i < len(self.vec)
    
    def _advance(self):
        while self.i < len(self.vec) and self.j >= len(self.vec[self.i]):
            self.i += 1
            self.j = 0