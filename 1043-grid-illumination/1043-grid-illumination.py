from collections import defaultdict
class Solution:
    def gridIllumination(self, N, lamps, queries):
        grid_rows = defaultdict(int)
        grid_cols = defaultdict(int)
        grid_diags1 = defaultdict(int)
        grid_diags2 = defaultdict(int)
        lamp_set = set()
        for x,y in lamps:
            if (x,y) in lamp_set: continue
            lamp_set.add((x,y))
            grid_rows[x] += 1
            grid_cols[y] += 1
            grid_diags1[x-y] += 1
            grid_diags2[x+y] += 1
        res = []
        for x,y in queries:
            if grid_rows[x] or grid_cols[y] or grid_diags1[x-y] or grid_diags2[x+y]:
                res.append(1)
            else:
                res.append(0)
            # turn off
            for nx in range(max(0,x-1), min(N,x+2)):
                for ny in range(max(0,y-1), min(N,y+2)):
                    if (nx,ny) in lamp_set:
                        lamp_set.remove((nx,ny))
                        grid_rows[nx] -= 1
                        grid_cols[ny] -= 1
                        grid_diags1[nx-ny] -= 1
                        grid_diags2[nx+ny] -= 1
        return res
