from typing import List

class ZigzagIterator:
    def __init__(self, v1: List[int], v2: List[int]):
        self.queue = []
        if v1:
            self.queue.append((0, v1))
        if v2:
            self.queue.append((0, v2))
        self.turn = 0
    
    def next(self) -> int:
        if not self.queue:
            return -1
        idx, vec = self.queue.pop(0)
        if idx + 1 < len(vec):
            self.queue.append((idx + 1, vec))
        return vec[idx]
    
    def hasNext(self) -> bool:
        return len(self.queue) > 0