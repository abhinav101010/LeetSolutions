class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        r, l, _ = 0, 0, 0
        for c in moves:
            if c == "R": r+=1
            if c == "L": l+=1
            if c == "_": _+=1

        if r == l: return _
        if r > l: return r-l+_
        if r < l: return l-r+_