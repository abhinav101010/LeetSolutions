# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import Optional

class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        self.res = 0
        
        def dfs(node):
            if not node:
                return 0
            left = dfs(node.left)
            right = dfs(node.right)
            left_len = left + 1 if node.left and node.left.val == node.val else 1
            right_len = right + 1 if node.right and node.right.val == node.val else 1
            self.res = max(self.res, left + right)
            return max(left_len, right_len)
        
        dfs(root)
        return self.res