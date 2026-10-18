class Solution:
    def winningPlayerCount(self, n, pick):
        cnt = [[0] * 11 for _ in range(n)]
        s = set()
        for x, y in pick:
            cnt[x][y] += 1
            if cnt[x][y] > x:
                s.add(x)
        return len(s)
