from collections import defaultdict
from typing import List

class Solution:
    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = defaultdict(list)
        
        def get_height(node):
            if not node:
                return -1
            h = 1 + max(get_height(node.left), get_height(node.right))
            res[h].append(node.val)
            return h
        
        get_height(root)
        return [res[k] for k in sorted(res.keys())]