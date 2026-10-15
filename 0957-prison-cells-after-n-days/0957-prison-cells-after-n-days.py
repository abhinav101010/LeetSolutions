class Solution:
    def prisonAfterNDays(self, cells: list[int], n: int) -> list[int]:
        seen = {}
        while n > 0:
            key = tuple(cells)
            if key in seen:
                # cycle detected
                cycle_len = seen[key] - n
                n %= cycle_len
            else:
                seen[key] = n
            if n == 0:
                break
            # compute next day
            next_cells = [0] * 8
            for i in range(1, 7):
                next_cells[i] = 1 if cells[i-1] == cells[i+1] else 0
            cells = next_cells
            n -= 1
        return cells
