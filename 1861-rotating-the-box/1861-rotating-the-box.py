from typing import List

class Solution:
    def rotateTheBox(self, boxGrid: List[List[str]]) -> List[List[str]]:
        m, n = len(boxGrid), len(boxGrid[0])
        
        # Rotate 90 degrees clockwise
        rotated = []
        for col in range(n):
            row = []
            for r in range(m - 1, -1, -1):
                row.append(boxGrid[r][col])
            rotated.append(row)
        
        # Apply gravity
        for col in range(m):
            write_row = n - 1
            for read_row in range(n - 1, -1, -1):
                if rotated[read_row][col] == '*':
                    write_row = read_row - 1
                elif rotated[read_row][col] == '#':
                    if write_row != read_row:
                        rotated[write_row][col] = '#'
                        rotated[read_row][col] = '.'
                    write_row -= 1
        
        return rotated