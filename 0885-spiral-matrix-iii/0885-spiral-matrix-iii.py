class Solution:
    def spiralMatrixIII(self, R: int, C: int, r0: int, c0: int) -> list[list[int]]:
        total = R * C
        res = [[r0, c0]]
        if total == 1:
            return res
        # directions: east, south, west, north
        dirs = [(0,1),(1,0),(0,-1),(-1,0)]
        dirIdx = 0
        step = 1
        r, c = r0, c0
        while len(res) < total:
            for _ in range(2):  # two directions per step length
                dr, dc = dirs[dirIdx]
                for _ in range(step):
                    r += dr
                    c += dc
                    if 0 <= r < R and 0 <= c < C:
                        res.append([r, c])
                        if len(res) == total:
                            return res
                dirIdx = (dirIdx + 1) % 4
            step += 1
        return res
