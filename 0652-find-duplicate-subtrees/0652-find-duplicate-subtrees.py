# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import defaultdict
from typing import List, Optional

class Solution:
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        res = []
        count = defaultdict(int)
        
        def dfs(node):
            if not node:
                return "#"
            s = str(node.val) + "," + dfs(node.left) + "," + dfs(node.right)
            count[s] += 1
            if count[s] == 2:
                res.append(node)
            return s
        
        dfs(root)
        return res