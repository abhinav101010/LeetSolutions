import heapq
from typing import List

class Solution:
    def closestKValues(self, root: Optional[TreeNode], target: float, k: int) -> List[int]:
        def inorder(node, res):
            if not node:
                return
            inorder(node.left, res)
            res.append(node.val)
            inorder(node.right, res)
        
        vals = []
        inorder(root, vals)
        heap = []
        for v in vals:
            heapq.heappush(heap, (abs(v - target), v))
        res = []
        for _ in range(k):
            res.append(heapq.heappop(heap)[1])
        return res