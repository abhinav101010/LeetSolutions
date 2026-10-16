class Solution:
    def numMovesStonesII(self, stones):
        stones.sort()
        n = len(stones)
        # max moves
        max_moves = max(stones[-1] - stones[1] - n + 2, stones[-2] - stones[0] - n + 2)
        # min moves - sliding window
        min_moves = n
        j = 0
        for i in range(n):
            while j < n and stones[j] - stones[i] < n:
                j += 1
            cost = n - (j - i)
            if j - i == n - 1 and stones[j-1] - stones[i] == n - 2:
                cost = 2
            min_moves = min(min_moves, cost)
        return [min_moves, max_moves]
