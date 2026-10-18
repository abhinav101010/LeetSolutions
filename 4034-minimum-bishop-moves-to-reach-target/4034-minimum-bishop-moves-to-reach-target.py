class Solution:
    def minBishopMoves(self, source, target):
        sr, sc = source
        tr, tc = target
        if (sr + sc) % 2 != (tr + tc) % 2:
            return -1
        if abs(sr - tr) == abs(sc - tc):
            return 1
        return 2
