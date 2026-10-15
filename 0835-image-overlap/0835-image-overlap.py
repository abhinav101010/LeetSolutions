class Solution:
    def largestOverlap(self, img1: list[list[int]], img2: list[list[int]]) -> int:
        n = len(img1)
        vector_count = {}
        for i in range(n):
            for j in range(n):
                if img1[i][j] == 1:
                    for x in range(n):
                        for y in range(n):
                            if img2[x][y] == 1:
                                vec = (x - i, y - j)
                                vector_count[vec] = vector_count.get(vec, 0) + 1
        return max(vector_count.values() or [0])
