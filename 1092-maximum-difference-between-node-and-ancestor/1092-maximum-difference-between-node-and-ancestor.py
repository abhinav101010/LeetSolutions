# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root):
        self.ans = 0
        def dfs(node, lo, hi):
            if not node:
                return
            self.ans = max(self.ans, abs(node.val - lo), abs(node.val - hi))
            dfs(node.left, min(lo, node.val), max(hi, node.val))
            dfs(node.right, min(lo, node.val), max(hi, node.val))
        dfs(root, root.val, root.val)
        return self.ans
