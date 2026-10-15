from collections import deque

class Solution:
    def slidingPuzzle(self, board: list[list[int]]) -> int:
        # flatten board
        start = ''.join(str(num) for row in board for num in row)
        target = "123450"
        if start == target:
            return 0
        # neighbors for each position in 2x3 grid
        neighbors = {
            0: [1, 3],
            1: [0, 2, 4],
            2: [1, 5],
            3: [0, 4],
            4: [1, 3, 5],
            5: [2, 4]
        }
        q = deque([start])
        visited = {start}
        steps = 0
        while q:
            for _ in range(len(q)):
                cur = q.popleft()
                if cur == target:
                    return steps
                zero_idx = cur.index('0')
                for nb in neighbors[zero_idx]:
                    lst = list(cur)
                    lst[zero_idx], lst[nb] = lst[nb], lst[zero_idx]
                    nxt = ''.join(lst)
                    if nxt not in visited:
                        visited.add(nxt)
                        q.append(nxt)
            steps += 1
        return -1
