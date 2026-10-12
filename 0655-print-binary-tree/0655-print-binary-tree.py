# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import List, Optional

class Solution:
    def printTree(self, root: Optional[TreeNode]) -> List[List[str]]:
        def get_height(node):
            if not node:
                return 0
            return 1 + max(get_height(node.left), get_height(node.right))
        
        h = get_height(root)
        m, n = h, (1 << h) - 1
        res = [[''] * n for _ in range(m)]
        
        def dfs(node, row, left, right):
            if not node or left > right:
                return
            mid = (left + right) // 2
            res[row][mid] = str(node.val)
            dfs(node.left, row + 1, left, mid - 1)
            dfs(node.right, row + 1, mid + 1, right)
        
        dfs(root, 0, 0, n - 1)
        return res