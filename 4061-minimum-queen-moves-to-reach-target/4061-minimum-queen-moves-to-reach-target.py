class Solution:
    def minQueenMoves(self, source, target):
        sr, sc = source
        tr, tc = target
        if sr == tr and sc == tc:
            return 0
        if sr == tr or sc == tc or abs(sr - tr) == abs(sc - tc):
            return 1
        return 2
