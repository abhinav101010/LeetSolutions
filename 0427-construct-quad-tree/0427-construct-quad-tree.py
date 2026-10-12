# Definition for a QuadTree node.
# class Node:
#     def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
#         self.val = val
#         self.isLeaf = isLeaf
#         self.topLeft = topLeft
#         self.topRight = topRight
#         self.bottomLeft = bottomLeft
#         self.bottomRight = bottomRight

class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        def is_uniform(r1, c1, r2, c2):
            val = grid[r1][c1]
            for i in range(r1, r2):
                for j in range(c1, c2):
                    if grid[i][j] != val:
                        return None
            return val
        
        def build(r1, c1, r2, c2):
            val = is_uniform(r1, c1, r2, c2)
            if val is not None:
                return Node(val == 1, True, None, None, None, None)
            
            mid_r = (r1 + r2) // 2
            mid_c = (c1 + c2) // 2
            
            return Node(
                True,
                False,
                build(r1, c1, mid_r, mid_c),
                build(r1, mid_c, mid_r, c2),
                build(mid_r, c1, r2, mid_c),
                build(mid_r, mid_c, r2, c2)
            )
        
        return build(0, 0, len(grid), len(grid))