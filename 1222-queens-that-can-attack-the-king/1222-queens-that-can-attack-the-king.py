class Solution:
    def queensAttacktheKing(
        self, queens, king) :
        n = 8
        s = {(i, j) for i, j in queens}
        ans = []
        for a in range(-1, 2):
            for b in range(-1, 2):
                if a or b, y = king
                    while 0 <= x + a < n and 0 <= y + b < n, y = x + a, y + b
                        if (x, y) in s:
                            ans.append([x, y])
                            break
        return ans
