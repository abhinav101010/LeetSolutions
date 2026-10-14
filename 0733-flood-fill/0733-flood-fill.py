from typing import List

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        rows = len(image)
        cols = len(image[0])
        orig = image[sr][sc]
        if orig == newColor:
            return image
        def dfs(r, c):
            if image[r][c] != orig:
                return
            image[r][c] = newColor
            if r > 0: dfs(r-1, c)
            if r+1 < rows: dfs(r+1, c)
            if c > 0: dfs(r, c-1)
            if c+1 < cols: dfs(r, c+1)
        dfs(sr, sc)
        return image
