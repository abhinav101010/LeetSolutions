from typing import List

class Solution:
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        res = []
        squares = []  # each as (left, right, height)
        cur_max = 0
        for left, side in positions:
            right = left + side
            base = 0
            for l, r, h in squares:
                if not (r <= left or right <= l):  # overlap
                    base = max(base, h)
            h = base + side
            squares.append((left, right, h))
            cur_max = max(cur_max, h)
            res.append(cur_max)
        return res
