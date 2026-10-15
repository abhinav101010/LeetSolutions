from typing import List

class Solution:
    def findBlackPixel(self, picture: List[List[str]], N: int) -> int:
        if not picture or not picture[0]:
            return 0
        m, n = len(picture), len(picture[0])
        # count blacks per row and per col
        rows = [0] * m
        cols = [0] * n
        # store row as string for comparison
        row_str = [''.join(row) for row in picture]
        for i in range(m):
            for j in range(n):
                if picture[i][j] == 'B':
                    rows[i] += 1
                    cols[j] += 1
        ans = 0
        for j in range(n):
            if cols[j] != N:
                continue
            # collect rows with black in this column
            rows_with_b = []
            for i in range(m):
                if picture[i][j] == 'B':
                    rows_with_b.append(i)
            # check each candidate row
            for i in rows_with_b:
                if rows[i] != N:
                    continue
                # check all rows in rows_with_b are identical to row i
                same = True
                for r in rows_with_b:
                    if row_str[r] != row_str[i]:
                        same = False
                        break
                if same:
                    ans += len(rows_with_b)  # each black pixel in this column qualifies
            # after processing column, break to avoid double counting? Actually each black pixel counted once per column.
            # But we added len(rows_with_b) for each qualifying row, which would overcount if multiple rows qualify.
            # Need to adjust: we should count each black pixel individually.
            # Let's change: for each black pixel that meets conditions, increment ans.
        # Re-do with per-pixel check
        ans = 0
        for i in range(m):
            for j in range(n):
                if picture[i][j] == 'B' and rows[i] == N and cols[j] == N:
                    # check column uniformity
                    same = True
                    for r in range(m):
                        if picture[r][j] == 'B' and row_str[r] != row_str[i]:
                            same = False
                            break
                    if same:
                        ans += 1
        return ans
