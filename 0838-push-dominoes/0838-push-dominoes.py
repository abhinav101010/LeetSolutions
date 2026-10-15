class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        force = [0] * n
        # left to right: influence of R
        f = 0
        for i in range(n):
            if dominoes[i] == 'R':
                f = n
            elif dominoes[i] == 'L':
                f = 0
            else:
                f = max(f - 1, 0)
            force[i] += f
        # right to left: influence of L
        f = 0
        for i in range(n-1, -1, -1):
            if dominoes[i] == 'L':
                f = n
            elif dominoes[i] == 'R':
                f = 0
            else:
                f = max(f - 1, 0)
            force[i] -= f
        # build result
        res = []
        for f in force:
            if f > 0:
                res.append('R')
            elif f < 0:
                res.append('L')
            else:
                res.append('.')
        return ''.join(res)
