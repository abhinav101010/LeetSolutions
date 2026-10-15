# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def longestConsecutive(self, root: TreeNode) -> int:
        self.best = 0
        def dfs(node):
            if not node:
                return (0, 0)  # inc, dec
            inc = dec = 1
            if node.left:
                li, ld = dfs(node.left)
                if node.left.val == node.val + 1:
                    inc = li + 1
                elif node.left.val == node.val - 1:
                    dec = ld + 1
            if node.right:
                ri, rd = dfs(node.right)
                if node.right.val == node.val + 1:
                    inc = max(inc, ri + 1)
                elif node.right.val == node.val - 1:
                    dec = max(dec, rd + 1)
            self.best = max(self.best, inc + dec - 1)
            return (inc, dec)
        dfs(root)
        return self.best
