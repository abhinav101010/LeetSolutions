# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def checkEqualTree(self, root: TreeNode) -> bool:
        def total_sum(node):
            if not node:
                return 0
            return node.val + total_sum(node.left) + total_sum(node.right)
        total = total_sum(root)
        self.found = False
        def dfs(node):
            if not node:
                return 0
            s = node.val + dfs(node.left) + dfs(node.right)
            if s * 2 == total and node != root:
                self.found = True
            return s
        dfs(root)
        return self.found
