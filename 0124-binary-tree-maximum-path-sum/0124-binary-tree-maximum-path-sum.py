# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import Optional

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.max_sum = float('-inf')
        
        def dfs(node: Optional[TreeNode]) -> int:
            if not node:
                return 0
            
            left_max = max(dfs(node.left), 0)
            right_max = max(dfs(node.right), 0)
            
            current_max = node.val + left_max + right_max
            self.max_sum = max(self.max_sum, current_max)
            
            return node.val + max(left_max, right_max)
        
        dfs(root)
        return self.max_sum